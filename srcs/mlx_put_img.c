/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:35:41 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/12 23:19:50 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_item(t_game *game)
{
	static int	loaded_img;
	static int	instance;

	if (loaded_img == 0)
	{
		game->texture = mlx_load_png("./asset/item.png");
		game->img_item = mlx_texture_to_image(game->mlx, game->texture);
		mlx_delete_texture(game->texture);
		loaded_img = 1;
	}
	mlx_image_to_window(game->mlx, game->img_item, (game->x * PIXEL), (game->y
			* PIXEL));
	game->img_item->instances[instance++].z = 1;
	if (!game->img_item)
	{
		perror("Error to load item.png\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	put_floor(t_game *game)
{
	static int	loaded_img;

	if (loaded_img == 0)
	{
		game->texture = mlx_load_png("./asset/floor.png");
		game->img_floor = mlx_texture_to_image(game->mlx, game->texture);
		mlx_delete_texture(game->texture);
		loaded_img = 1;
	}
	mlx_image_to_window(game->mlx, game->img_floor, (game->x * PIXEL), (game->y
			* PIXEL));
	game->img_floor->instances[game->count_instance_floor++].z = 0;
	if (!game->img_floor)
	{
		perror("Error to load floor.png\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	put_wall(t_game *game)
{
	static int	loaded_img;
	static int	instance;

	if (loaded_img == 0)
	{
		game->texture = mlx_load_png("./asset/wall.png");
		game->img_wall = mlx_texture_to_image(game->mlx, game->texture);
		mlx_delete_texture(game->texture);
		loaded_img = 1;
	}
	mlx_image_to_window(game->mlx, game->img_wall, (game->x * PIXEL), (game->y
			* PIXEL));
	game->img_wall->instances[instance++].z = 1;
	if (!game->img_wall)
	{
		perror("Error to load wall.png\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	put_exit(t_game *game)
{
	static int	loaded_img;
	static int	instance;

	if (loaded_img == 0)
	{
		game->texture = mlx_load_png("./asset/exit.png");
		game->img_exit = mlx_texture_to_image(game->mlx, game->texture);
		mlx_delete_texture(game->texture);
		loaded_img = 1;
	}
	mlx_image_to_window(game->mlx, game->img_exit, (game->x * PIXEL), (game->y
			* PIXEL));
	game->img_exit->instances[instance++].z = 1;
	if (!game->img_exit)
	{
		perror("Error to load exit.png\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void	put_player(t_game *game)
{
	static int	loaded_img;
	static int	instance;

	if (loaded_img == 0)
	{
		game->texture = mlx_load_png("./asset/player.png");
		game->img_player = mlx_texture_to_image(game->mlx, game->texture);
		mlx_delete_texture(game->texture);
		loaded_img = 1;
	}
	mlx_image_to_window(game->mlx, game->img_player, (game->x * PIXEL), (game->y
			* PIXEL));
	game->img_player->instances[instance++].z = 5;
	if (!game->img_player)
	{
		perror("Error to load player.png\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}
