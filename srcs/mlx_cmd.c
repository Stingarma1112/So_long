/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:21:21 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/12 20:56:51 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_texture_map(t_game *game)
{
	game->x = 0;
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			put_floor(game);
			if (game->map[game->y][game->x] == '1')
				put_wall(game);
			if (game->map[game->y][game->x] == 'E')
				put_exit(game);
			if (game->map[game->y][game->x] == 'C')
				put_item(game);
			if (game->map[game->y][game->x] == 'P')
				put_player(game);
			game->x++;
		}
		game->y++;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	
	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(game, game->player_x, game->player_y - 1, UP);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(game, game->player_x, game->player_y + 1, DOWN);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(game, game->player_x - 1, game->player_y, LEFT);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(game, game->player_x + 1, game->player_y, RIGHT);
}

int	is_valid_move(t_game *game, int nx, int ny)
{
	static int	i;

	if (game->map[ny][nx] == '1')
		return (0);
	if (game->map[ny][nx] == 'C')
	{
		game->item_collected++;
		game->map[ny][nx] = '0';
		put_floor_after_collec(game, nx, ny);
	}
	if (game->map[ny][nx] == 'E' && game->item_collected == game->collectible_count)
	{
		ft_printf("You win\n");
		ft_printf("You collected %d/%d items\n", game->item_collected, game->collectible_count);
		ft_printf("You made %d moves\n", i);
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	ft_printf("move : %d\n", ++i);
	return (1);
}

void	move_player(t_game *game, int nx, int ny, int dir)
{
	if (is_valid_move(game, nx, ny))
	{
		if (dir == UP)
			game->img_player->instances->y -= PIXEL;
		if (dir == DOWN)
			game->img_player->instances->y += PIXEL;
		if (dir == LEFT)
			game->img_player->instances->x -= PIXEL;
		if (dir == RIGHT)
			game->img_player->instances->x += PIXEL;
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = nx;
		game->player_y = ny;
		game->map[game->player_y][game->player_x] = 'P';
	}
}
