/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:44:43 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/12 20:37:00 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 64

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_game
{
	char			**map;
	int				width;
	int				height;
	int				player_count;
	int				exit_count;
	int				collectible_count;
	int				item_collected;
	int				x;
	int				y;
	int				player_x;
	int				player_y;
	int				count_instance_floor;
	mlx_t			*mlx;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_player;
	mlx_image_t		*img_item;
	mlx_texture_t	*texture;
}					t_game;

enum	e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

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
void	init_mlx(t_game *game);
void	free_game(t_game *game);

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
void	put_floor_after_collec(t_game *game, int nx, int ny);

//===============MLX_PUT_IMG==========//

void	put_floor(t_game *game);
void	put_wall(t_game *game);
void	put_exit(t_game *game);
void	put_player(t_game *game);
void	put_item(t_game *game);

//===============MLX_CMD==============//
void	put_texture_map(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	move_player(t_game *game, int nx, int ny, int dir);
int		is_valid_move(t_game *game, int nx, int ny);

void print_map(char **map, t_game *game);

#endif