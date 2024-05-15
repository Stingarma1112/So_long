/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:45:38 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/09 03:12:56 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest_ptr > src_ptr)
		while (n--)
			dest_ptr[n] = src_ptr[n];
	else
		while (n--)
			*dest_ptr++ = *src_ptr++;
	return (dest);
}

char	*ft_strjoin(char *line, char *buff)
{
	char	*full_line;
	int		len_line;
	int		len_buff;

	if (!line)
		line = (char *)ft_calloc(1, sizeof(char));
	if (!line || !buff)
		return (NULL);
	len_line = ft_strlen(line);
	len_buff = ft_strlen(buff);
	full_line = (char *)ft_calloc(len_line + len_buff + 1, sizeof(char));
	if (!full_line)
	{
		free(line);
		return (NULL);
	}
	ft_memmove(full_line, line, len_line);
	ft_memmove(full_line + len_line, buff, len_buff + 1);
	free(line);
	return (full_line);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (0);
	if (len_s - start < len)
		len = len_s - start;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	ft_memmove(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	len;
	size_t	i;

	len = nmemb * size;
	if (len / size != nmemb)
		return (NULL);
	tab = malloc(len);
	if (!tab)
		return (0);
	i = 0;
	while (i < len)
		((char *) tab)[i++] = 0;
	return (tab);
}
