/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/08 19:34:40 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;
	t_tile	img;
	
	map = NULL;
	if (check_parameters(argc, argv) == 1)
	{
		printf("Parameters invalid\n");
		return (0);
	}
	game = map_values(argv[1], game);
	map = read_map(map, argv[1], game);
	printf("width value %d\n", game.width);
	printf("heigt value %d\n", game.height);
	if (check_config(map, game) == 0)
		exit_error(map);
	game = copy_map_to_game(map, game);
	game = path_finding(game);
	print_tab(game.map);
	write(1, "\n", 1);
	print_tab(game.path);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64,
		"so_long");
	//img.img = mlx_new_image(game.mlx, 200, 200);
	img = images_id(game, img);
	load_images(game, img);
	//mlx_put_image_to_window(game.mlx, game.win, img.wall, 64, 64);
	// img.wall = mlx_xpm_file_to_image(game.mlx, "../sprites/Image0016.xpm",
	// 	&img.width, &img.height);
	// mlx_put_image_to_window(game.mlx, game.win, img.wall, 0, 0) ;
	mlx_loop(game.mlx);
	free_tab(map);
	free_tab(game.map);
	free_tab(game.path);
	return (0);
}

