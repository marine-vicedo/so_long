/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/02 18:11:31 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;
	
	map = NULL;
	if (check_parameters(argc, argv) == 1)
	{
		printf("Parameters invalid\n");
		return (0);
	}
	game = map_values(argv[1], game);
	map = read_map(map, argv[1], game);
	//printf("width value %d\n", game.width);
	//printf("heigt value %d\n", game.height);
	if (check_config(map, game) == 0)
		exit_error(map);
	game = copy_map_to_game(map, game);
	game = path_finding(game);
	//print_tab(game.map);
	//write(1, "\n", 1);
	//print_tab(game.path);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 500, game.height * 500,
		"so_long");
	mlx_loop_hook(game.mlx, display_map, &game);
	mlx_loop(game.mlx);
	free_tab(map);
	free_tab(game.map);
	free_tab(game.path);
	return (0);
}

