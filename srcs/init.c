/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 03:44:09 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/12 21:00:07 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_struct(t_game *game)
{
	game->map = NULL;
	game->height = 0;
	game->width = 0;
	game->player_count = 0;
	game->exit_count = 0;
	game->collectible_count = 0;
	game->count_instance_floor = 0;
	game->item_collected = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->x = 0;
	game->y = 0;
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init((game->width * PIXEL), (game->height * PIXEL), "So_long", true);
	if (!game->mlx)
	{
		perror("Error in initializing mlx\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	free_game(t_game *game)
{
	if (game->img_player)
		mlx_delete_image(game->mlx, game->img_player);
	if (game->img_exit)	
		mlx_delete_image(game->mlx, game->img_exit);
	if (game->img_wall)
		mlx_delete_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_delete_image(game->mlx, game->img_floor);
	if (game->img_item)
		mlx_delete_image(game->mlx, game->img_item);
	if (game->map)
		free_map_main(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
}
