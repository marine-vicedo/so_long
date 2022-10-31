/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:26:36 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/31 20:14:16 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game copy_map_to_game(char **map, t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game.map = (char **)malloc(sizeof(char *) * (game.height + 1));
	if (!game.map)
		exit(0);
	while (map[y])
	{
		game.map[y] = (char *)malloc(sizeof(char) * game.width + 1);
		if (!game.map)
		{
			free_tab(game.map);
			exit(0);
		}
		while(x < game.width)
		{
			game.map[y][x] = map[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	return (game);
}

t_game init_path(t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game.path = (char **)malloc(sizeof(char *) * (game.height + 1));
	if (!game.path)
		exit(0);
	while (y < game.height)
	{
		game.path[y] = (char *)malloc(sizeof(char) * game.width + 1);
		if (!game.path)
		{
			free_tab(game.path);
			exit(0);
		}
		while(x < game.width)
		{
			game.path[y][x] = '0';
			x++;
		}
		x = 0;
		y++;
	}
	return (game);
}