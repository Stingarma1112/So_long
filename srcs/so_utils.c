/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:56:35 by lsaumon           #+#    #+#             */
/*   Updated: 2024/07/06 19:35:33 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int i = 0;
	
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_filename(char *filename)
{
	size_t	len;
	int		result;
	
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	result = ft_strcmp(&filename[len - 4], ".ber") == 0;
	return (result);
}
