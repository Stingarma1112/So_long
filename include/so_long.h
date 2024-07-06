/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:44:43 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/06 19:59:53 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct game
{
	char	**map;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
}				t_game;

//===============MAIN==================//

void    free_map_main(t_game *game);
int		check_all(int argc, char **argv, t_game *game);
int		check_all_2(t_game *game);

//===============MAP_DEF===============//

int read_map(char *filename, t_game *game);

//===============PARSING===============//

int	check_line(t_game *game);
int	check_car(t_game *game);
int	validate_char(t_game *game);
int	validate_perimeter(t_game *game);

//===============INIT==================//

void	init_struct(t_game *game);

//===============FLOOD_FILL============//

void	flood_fill(char **map, int x, int y, int height, int width);
char	**copy_map(char **map, int height, int width);
void	free_map(char **map, int height);
int		check_access(t_game *game, char **temp_map);
int		check_flood_fill(t_game *game);

//===============SO_UTILS============//

char	*ft_strcpy(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
int		check_filename(char *filename);

void print_map(char **map, t_game *game);

#endif