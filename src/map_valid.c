/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:33:05 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/15 15:12:31 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!(invalid_character(game, x, y)))
	{
		ft_putstr_fd("Error : invalid map", 2);
		return (0);
	}
	if (!(closed_by_walls(game, y)))
	{
		ft_putstr_fd("Error : the map is not surrounded by walls", 2);
		return (0);
	}
	if (!(check_player(game, x, y)))
	{
		ft_putstr_fd("Error : needs 1 player", 2);
		return (0);
	}
	if (!(check_collect_exit(game, x, y)))
	{
		ft_putstr_fd("Error : needs 1 exit AND 1 or + items in the map", 2);
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
	if (!check_format(game))
	{
		ft_putstr_fd("Error : the map must be rectangular", 2);
		return (0);
	}
	if (!check_matrix(game, x, y))
		return (0);
	return (1);
}
