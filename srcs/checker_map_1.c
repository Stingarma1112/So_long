/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:43:46 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/21 18:00:52 by lsaumon          ###   ########.fr       */
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

void	add_new_line(t_map *map)
{
	//realloc pour avoir la taille de la ligne + toute les ligne du tableau
}

void	ft_read_map(t_map *map)
{
	map->line = get_next_line(map->fd);
	while() // boucle pour implementer les lignes dans le tableau
	map->line = map->stock_map;
	printf("%s", map->line);
}