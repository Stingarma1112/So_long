/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_definition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:12:47 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/12 23:13:09 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	map_height(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		perror("Error map doesn't exist\n");
		return (0);
	}
	while (line != NULL)
	{
		game->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	game->map[game->height] = "\0";
	if (!game->map)
	{
		perror("Error allocating memory\n");
		return (0);
	}
	return (1);
}

static void	erase_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

static int	pre_read(int fd, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		erase_n(line);
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
		{
			perror("Error allocating memory\n");
			free(line);
			close(fd);
			return (0);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	read_map(char *filename, t_game *game)
{
	int	fd;

	if (!map_height(filename, game))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error openning file\n");
		return (0);
	}
	if (!pre_read(fd, game))
		return (0);
	close(fd);
	game->width = ft_strlen(game->map[0]);
	return (1);
}
