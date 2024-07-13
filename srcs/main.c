/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:58:27 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/12 23:13:12 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(char **map, t_game *game)
{
	int	i;

	i = -1;
	while (++i, map && i < game->height)
	{
		printf("%s\n", map[i]);
	}
}

void	free_map_main(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	check_all(int argc, char **argv, t_game *game)
{
	(void)argc;
	if (!read_map(argv[1], game))
	{
		ft_printf("Error reading map\n");
		return (1);
	}
	if (!check_line(game))
	{
		free_map_main(game);
		return (1);
	}
	if (!validate_char(game))
	{
		free_map_main(game);
		return (1);
	}
	if (!validate_perimeter(game))
	{
		free_map_main(game);
		return (1);
	}
	return (0);
}

int	check_all_2(t_game *game)
{
	if (!check_car(game))
	{
		free_map_main(game);
		return (1);
	}
	if (!check_flood_fill(game))
	{
		free_map_main(game);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map_file>\n");
		return (1);
	}
	if (!check_filename(argv[1]))
	{
		ft_printf("Error need a .ber extension\n");
		return (1);
	}
	init_struct(&game);
	if (check_all(argc, argv, &game) != 0)
		return (1);
	if (check_all_2(&game) != 0)
		return (1);
	init_mlx(&game);
	put_texture_map(&game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	free_game(&game);
	return (0);
}
// mlx_terminate();