/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinevicedo <marinevicedo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:33:05 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/10 11:05:08 by marineviced      ###   ########.fr       */
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

int	check_format(t_game *game)
{
	int	line;

	line = 0;
	while (game->map[line] != NULL)
	{
		if (ft_strlen(game->map[line]) != game->width)
			return (0);
		line++;
	}
	return (1);
}

int	check_matrix(t_game *game, int x, int y)
{
	if (invalid_character(game, x, y) == 0)
	{
		ft_putstr_fd("Error : invalid map\n", 2);
		return (0);
	}
	if (check_player(game, x , y) == 0)
	{
		ft_putstr_fd("Error : needs 1 player !\n", 2);
		return (0);
	}
	if (check_collect_exit(game, x, y) == 0)
	{
		ft_putstr_fd("Error : no exit or no collectibles in the map !\n", 2);
		return (0);
	}
	if (closed_by_walls(game, y) == 0)
	{
		ft_putstr_fd("Error : the map is not surrounded by walls\n", 2);
		return (0);
	}
	return (1);
}

int	map_is_valid(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (check_format(game) == 0)
		return (0);
	if (check_matrix(game, x, y) == 0)
		return (0);
	return (1);
}
