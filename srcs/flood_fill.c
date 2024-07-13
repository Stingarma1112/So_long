/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 02:47:28 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/12 23:25:07 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(char **map, int y, int x, t_game *game)
{
	int	width;
	int	height;

	width = game->width;
	height = game->height;
	if (x < 0 || x >= width || y < 0 || y >= height || map[y][x] == '1'
		|| map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, y + 1, x, game);
	flood_fill(map, y - 1, x, game);
	flood_fill(map, y, x + 1, game);
	flood_fill(map, y, x - 1, game);
}

char	**copy_map(char **map, int height, int width)
{
	char	**temp_map;
	int		i;

	temp_map = malloc(sizeof(char *) * height);
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		temp_map[i] = malloc(sizeof(char) * (width + 1));
		if (!temp_map[i])
		{
			while (i-- > 0)
				free(temp_map[i]);
			free(temp_map);
			return (NULL);
		}
		ft_strcpy(temp_map[i], map[i]);
		i++;
	}
	return (temp_map);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_access(t_game *game, char **temp_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((game->map[i][j] == 'C' || game->map[i][j] == 'E')
				&& temp_map[i][j] != 'F')
			{
				perror("Error path blocked\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_flood_fill(t_game *game)
{
	char	**temp_map;

	temp_map = copy_map(game->map, game->height, game->width);
	if (!temp_map)
		return (0);
	flood_fill(temp_map, game->player_y, game->player_x, game);
	if (!check_access(game, temp_map))
	{
		free_map(temp_map, game->height);
		return (0);
	}
	free_map(temp_map, game->height);
	return (1);
}
