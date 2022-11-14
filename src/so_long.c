/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/14 15:39:17 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!check_args(argc, argv))
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_values(argv[1], game);
	read_map(argv[1], game);
	if (!map_is_valid(game))
		exit_error(game, 2);
	pathfinding(game);
	//print_tab(game->path);
	display_game(game);
	return (0);
}
