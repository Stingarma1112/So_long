/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:43:16 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/04 19:38:59 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_strchr_gnl(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
			return ((char *) &str[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) &str[i]);
	return (0);
}

void	ft_update_line_and_buffer(char **line, char *buffer)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	len = ft_strlen_gnl(*line + i + 1);
	ft_memmove_gnl(buffer, *line + i + 1, len);
	buffer[len] = '\0';
	if ((*line)[i] == '\n')
	{
		tmp = ft_substr_gnl(*line, 0, i + 1);
		if (!tmp)
			return ;
		free(*line);
		*line = tmp;
	}
}

void	ft_read(int fd, char **line, char *buffer, int *br)
{
	*br = 1;
	while (!ft_strchr_gnl(buffer, '\n') && *br != 0)
	{
		*br = read(fd, buffer, BUFFER_SIZE);
		if (*br == -1)
		{
			buffer[0] = '\0';
			free(*line);
			*line = NULL;
			return ;
		}
		buffer[*br] = '\0';
		*line = ft_strjoin_gnl(*line, buffer);
		if (!*line)
			return ;
	}
}

int	ft_check(int br, char **line)
{
	if (br == -1 || !(*line) || (*line)[0] == '\0')
	{
		free(*line);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char		buffer[1024][BUFFER_SIZE + 1];
	char			*line;
	int				br;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (buffer[fd][0] != '\0')
		line = ft_strjoin_gnl(NULL, buffer[fd]);
	ft_read(fd, &line, buffer[fd], &br);
	if (!ft_check(br, &line))
		return (NULL);
	if (br <= 0)
		return (line);
	ft_update_line_and_buffer(&line, buffer[fd]);
	return (line);
}
