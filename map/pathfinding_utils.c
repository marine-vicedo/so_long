/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:00:39 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/01 18:04:34 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_pos_player(t_game game, int x, int y)
{
	while (y < game.height)
	{
		while (x < game.width)
		{
			if (game.path[y][x] == 'P')
			{
				if (game.path[y + 1][x] == '0' || game.path[y + 1][x] == 'C')
					return (1);
				if (game.path[y - 1][x] == '0' || game.path[y - 1][x] == 'C')
					return (1);
				if (game.path[y][x + 1] == '0' || game.path[y][x + 1] == 'C')
					return (1);
				if (game.path[y][x - 1] == '0' || game.path[y][x - 1] == 'C')
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

t_game	move_pos_player(t_game game, int x, int y)
{
	while (y < game.height)
	{
		while (x < game.width)
		{
			if (game.path[y][x] == 'P')
			{
				if (game.path[y + 1][x] == '0' || game.path[y + 1][x] == 'C')
					game.path[y + 1][x] = 'P';
				if (game.path[y - 1][x] == '0' || game.path[y - 1][x] == 'C')
					game.path[y - 1][x] = 'P';
				if (game.path[y][x + 1] == '0' || game.path[y][x + 1] == 'C')
					game.path[y][x + 1] = 'P';
				if (game.path[y][x - 1] == '0' || game.path[y][x - 1] == 'C')
					game.path[y][x - 1] = 'P';
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (game);
}

int	all_items_are_collected(t_game game, int x, int y)
{
	while (y < game.height)
	{
		while (x < game.width)
		{
			if (game.path[y][x] == 'C')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	valid_path(t_game game, int x, int y)
{
	while (y < game.height)
	{
		while (x < game.width)
		{
			if (game.path[y][x] == 'E')
			{
				if (game.path[y + 1][x] == 'P')
					return (1);
				if (game.path[y - 1][x] == 'P')
					return (1);
				if (game.path[y][x + 1] == 'P')
					return (1);
				if (game.path[y][x - 1] == 'P')
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
