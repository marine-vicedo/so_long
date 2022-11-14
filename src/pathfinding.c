/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:26:36 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/14 13:48:53 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**init_path(t_game *game, int y)
{
	game->path = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->path)
		return (NULL);
	while (y < game->height)
	{
		game->path[y] = ft_strdup(game->map[y]);
		y++;
	}
	game->path[y] = NULL;
	return (game->path);
}

void	check_valid_path(t_game *game, int x, int y)
{
	while (check_pos_player(game, x, y))
		move_pos_player(game, x, y);
	if (!(valid_path(game, x, y) && all_items_are_collected(game, x, y)))
		exit_error(game, 3);
}

void	pathfinding(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->path = init_path(game, y);
	check_valid_path(game, x, y);
}
