/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:41:53 by lsaumon           #+#    #+#             */
/*   Updated: 2024/05/21 17:49:14 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/So_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	open_map_file(argv[1], &map);
	ft_read_map(&map);
	free(map.line);
	return (0);
}