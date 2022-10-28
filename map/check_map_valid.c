/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:52:26 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/28 19:24:28 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	invalid_character(char **map, t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (x < game.width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E' || map[y][x] == 'P'
				|| map[y][x] == '1' || map[y][x] == '0')
				x++;
			else
				return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}

int	check_player(char **map, t_game game)
{
	int	x;
	int	y;
	int	player;

	x = 0;
	y = 0;
	player = 0;
	while (map[y])
	{
		while (x < game.width)
		{
			if (map[y][x] == 'P')
				player++;
			x++;
		}
		x = 0;
		y++;
	}
	if (player == 1)
		return (1);
	else
		return (0);
}

int	check_collect_exit(char **map, t_game game)
{
	int	x;
	int	y;
	int	collect;
	int	exit;

	x = 0;
	y = 0;
	collect = 0;
	exit = 0;
	while (map[y])
	{
		while (x < game.width)
		{
			if (map[y][x] == 'C')
				collect++;//save this value in a struct !
			if (map[y][x] == 'E')
				exit++;//save this value in a struct ?
			x++;
		}
		x = 0;
		y++;
	}
	if (collect == 0 || exit == 0)
		return (0);
	return (1);
}

int	closed_by_walls(char **map, t_game game)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (y == 0 || y == game.height - 1)
		{
			if (ft_strchr(map[y], '1') == 0)
				return (0);
		}
		else if (y > 0 && y < game.height - 1)
		{	
			if (map[y][0] != '1' || map[y][game.width - 1] != '1')
				return (0);
		}
		y++;
	}
	return (1);
}
