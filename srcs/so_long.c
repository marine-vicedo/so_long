/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/11 18:50:35 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -Wall -Wextra -Werror -I ../minilibx-linux/ *.c ../get_next_line_V2/*.c -L ../minilibx-linux -lmlx -lXext -lX11 -lz -lm

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
	print_tab(game->map);
	if (!map_is_valid(game))
		exit_error(game);
	path_finding(game);
	write(1, "\n", 1);
	print_tab(game->path);
	display_game(game);
	// free_tab(game->map);
	// free_tab(game->path);
	// free(game);
	return (0);
}

