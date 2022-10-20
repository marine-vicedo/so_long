/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:33:05 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/20 19:36:22 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char **map)
{
	size_t	width;
	int	line;

	line = 0;
	width = ft_strlen(map[line]);
	line++;
	while (map[line] != NULL)
	{
		if (ft_strlen(map[line]) != width)
			return (0);
		line++;
	}
	return (1);
}

int walls_y(char **map)
{
	int	line;
	int	size;;

	line = 0;
	size = count_tablines(map);
	if (ft_strchr(map[line], '1') == 0)
			return (0);
	line = (size - 1);
	if (ft_strchr(map[line], '1') == 0)
		return (0);
	return (1);
}

/*int	closed_by_walls(char **map)
{

	
}*/

int	check_config(char **map)
{
	if (check_format(map) == 0)
	{
		printf("Error config (format)\n");
		return (0);
	}
	if (walls_y(map) == 0)
	{
		printf("Error config (walls)\n");
		return (0);
	}
	return (1);
}