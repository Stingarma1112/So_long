/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:24:32 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/21 17:56:02 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_map
{
	char	**stock_map;
	int		fd;
	char	*line;
	int		height;
}t_map;

//==CHECKER_MAP_1==//

void	open_map_file(char *file_path, t_map *map);
void	ft_read_map(t_map *map);

#endif