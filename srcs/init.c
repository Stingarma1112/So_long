/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 03:44:09 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/06 04:38:05 by lsaumon          ###   ########.fr       */
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
	game->player_x = 0;
	game->player_y = 0;
	game->x = 0;
	game->y = 0;
}
