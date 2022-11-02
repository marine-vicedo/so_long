/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:33:05 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/01 12:31:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* check is :
- the table follow the above rules : an invalid character (something else than
 0, 1, C, E, P) (OK)
OR a line with a different lenght (OK) OR more than one player/no exit OR
no collectibles (OK)
OR the map is not closed by walls (OK) :
print an error msg, invalid the map, free and exit*/

int	check_format(char **map, t_game game)
{
	int	line;

	line = 0;
	while (map[line] != NULL)
	{
		if (ft_strlen(map[line]) != game.width)
			return (0);
		line++;
	}
	return (1);
}

int	check_matrix(char **map, t_game game, int x, int y)
{
	if (invalid_character(map, game, x, y) == 0)
	{
		printf("Error : Invalid character in the map\n");
		return (0);
	}
	if (check_player(map, game, x , y) == 0)
	{
		printf("Error : needs 1 player !\n");
		return (0);
	}
	if (check_collect_exit(map, game, x, y) == 0)
	{
		printf("Error : There is no exit or no collectibles in the map !\n");
		return (0);
	}
	if (closed_by_walls(map, game, y) == 0)
	{
		printf("Error config (walls)\n");
		return (0);
	}
	return (1);
}

int	check_config(char **map, t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (check_format(map, game) == 0)
	{
		printf("Error config (format)\n");
		return (0);
	}
	if (check_matrix(map, game, x, y) == 0)
		return (0);
	return (1);
}
