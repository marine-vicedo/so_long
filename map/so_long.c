/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/09 17:26:43 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -Wall -Wextra -Werror -I ../minilibx-linux/ *.c ../get_next_line_V2/*.c -L ../minilibx-linux -lmlx -lXext -lX11 -lz -lm
#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;
	//t_tile	img;
	
	map = NULL;
	//printf("%d\n", check_parameters(argc, argv));
	if (!check_args(argc, argv))
		return (0);
	game = map_values(argv[1], game);
	map = read_map(map, argv[1], game);
	printf("ici");
	if (!map_is_valid(map, game))
		exit_error(map);
	game = copy_map_to_game(map, game);
	game = path_finding(game);
	// print_tab(game.map);
	// write(1, "\n", 1);
	// print_tab(game.path);
	//display_game(&game, &img);
	free_tab(map);
	free_tab(game.map);
	free_tab(game.path);
	return (0);
}

