/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:33:05 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/26 19:17:21 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check is :
- the table follow the above rules : an invalid character (something else thant 0, 1, C, E, P)
OR a line with a different lenght OR more than one player : print an error msg, invalid the map, free and exit*/

int	check_format(char **map, t_game *game)
{
	//size_t	width;
	int	line;

	line = 0;
	//width = ft_strlen(map[line]);
	//line++;
	while (map[line] != NULL)
	{
		if (ft_strlen(map[line]) != game->width)
		{
			printf("%ld\n", game->width);
			printf("%ld\n", ft_strlen(map[line]));
			return (0);
		}
		line++;
	}
	return (1);
}

/*int	invalid_character(char **map)
{
	int	height;
	int	width;
	t_data	map;

	height = count_tablines(map);
	map.height = height;
	width = ft_strlen(map[1]);
	map.width = width;

	while ()
}*/

/*int walls_y(char **map)
{
	int	line;
	int	height;

	line = 0;
	height = count_tablines(map);
	if (ft_strchr(map[line], '1') == 0)
			return (0);
	line = (height - 1);
	if (ft_strchr(map[line], '1') == 0)
		return (0);
	return (1);
}*/

/*int	closed_by_walls(char **map)
{

	
}*/

int	check_config(char **map, t_game *game)
{
	if (check_format(map, game) == 0)
	{
		printf("Error config (format)\n");
		return (0);
	}
	/*if (invalid_char(map) == 0)
	{
		printf("Invalid character\n");
		return (0);
	}*/
	/*if (walls_y(map) == 0)
	{
		printf("Error config (walls)\n");
		return (0);
	}*/
	return (1);
}