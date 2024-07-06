/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 00:04:22 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/06 19:30:25 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_line(t_game *game)
{
	int		i;
	int	stock;

	i = 0;
	stock = 0;
	while (game->map && i < game->height)
	{
		stock = ft_strlen(game->map[i]);
		if (stock != game->width)
		{
			perror("Error invalid map\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	count_pec(t_game *game)
{
	
	game->player_count = 0;
	game->exit_count = 0;
	game->collectible_count = 0;
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[game->y][game->x] == 'P')
			{
				game->player_count++;
				game->player_x = game->x;
				game->player_y = game->y;
			}
			if (game->map[game->y][game->x] == 'E')
				game->exit_count++;
			if (game->map[game->y][game->x] == 'C')
				game->collectible_count++;
			game->x++;
		}
		game->y++;
	}
	return (1);
}

int	check_car(t_game *game)
{
	count_pec(game);
	
	if (game->player_count != 1)
	{
		perror("Error invalid number of player\n");
		return (0);
	}
	if (game->exit_count != 1)
	{
		perror("Error invalid number of exit\n");
		return (0);
	}
	if (game->collectible_count < 1)
	{
		perror("Error no collectible on the map\n");
		return (0);
	}
	return (1);
}

int	validate_char(t_game *game)
{
	game->y = 0;
	
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[game->y][game->x] != 'P' 
				&& game->map[game->y][game->x] != 'E'
				&& game->map[game->y][game->x] != 'C'
				&& game->map[game->y][game->x] != '1'
				&& game->map[game->y][game->x] != '0')
			{
				perror("Error invalid character found in map\n");
				return (0);
			}
			game->x++;
		}
		game->y++;
	}
	return (1);
}

int	validate_perimeter(t_game *game)
{
	game->x = 0;
	while (game->x < game->width)
	{
		if (game->map[0][game->x] != '1' ||
			game->map[game->height - 1][game->x] != '1')
		{
			perror("Error with the perimeter of the map\n");
			return (0);
		}
		game->x++;
	}
	game->x = 0;
	while (game->x < game->height)
	{
		if (game->map[game->x][0] != '1' ||
			game->map[game->x][game->width - 1] != '1')
		{
			perror("Error with the perimeter of the map\n");
			return (0);
		}
		game->x++;
	}
	return (1);
}
