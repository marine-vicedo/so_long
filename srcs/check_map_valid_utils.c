/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinevicedo <marinevicedo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:52:26 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/10 17:58:48 by marineviced      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	invalid_character(t_game *game, int x, int y)
{
	while (game->map[y])
	{
		while (x < game->width)
		{
			if (game->map[y][x] == 'C' || game->map[y][x] == 'E' || game->map[y][x] == 'P'
				|| game->map[y][x] == '1' || game->map[y][x] == '0')
				x++;
			else
				return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}

int	check_player(t_game *game, int x, int y)
{
	int	player;

	player = 0;
	while (game->map[y])
	{
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
				player++;
			x++;
		}
		x = 0;
		y++;
	}
	if (player == 1)
		return (1);
	return (0);
}

int	check_collect_exit(t_game *game, int x, int y)
{
	//int	collect;
	int	exit;

	game->item = 0;
	exit = 0;
	while (game->map[y])
	{
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				game->item++;
			if (game->map[y][x] == 'E')
				exit++;
			x++;
		}
		x = 0;
		y++;
	}
	if (game->item == 0 || exit == 0)
		return (0);
	return (1);
}

int	closed_by_walls(t_game *game, int y)
{
	while (game->map[y])
	{
		if (y == 0 || y == game->height - 1)
		{
			if (ft_strchr(game->map[y], '1') == 0)
				return (0);
		}
		else if (y > 0 && y < game->height - 1)
		{	
			if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
				return (0);
		}
		y++;
	}
	return (1);
}
