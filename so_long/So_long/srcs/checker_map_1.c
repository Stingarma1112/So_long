/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:43:46 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/15 05:01:37 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/So_long.h"

void	open_map_file(char *file_path, t_map *map)
{
	map->fd = open(file_path, O_RDONLY);
	if (map->fd == -1)
	{
		perror("Error openning file");
		exit(EXIT_FAILURE);
	}
}

void	add_new_line(t_map map)
{
	//fonction ajouter une nouvelle ligne pour co;pleter read map afin de stocker + lire les ligne de la map !!!
}

void	read_map(t_map *map)
{
	char	*line;
	
	while ((line = get_next_line(map->fd)) != NULL)
	{
		map->stock_map = malloc (sizeof(char *) * ft_strlen(line) + 1);
		map->stock_map = ft_strdup(line);
		free(map->stock_map);
	}
}
