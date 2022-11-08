/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:43:57 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:25 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	images_id(t_game game, t_tile img)
{
	img.width = 64;
	img.height = 64;
	
	img.wall = mlx_xpm_file_to_image(game.mlx, "../sprites/Image0016.xpm",
		&img.width, &img.height);
	img.empty = mlx_xpm_file_to_image(game.mlx, "../sprites/fond.xpm",
		&img.width, &img.height);
	img.player = mlx_xpm_file_to_image(game.mlx, "../sprites/perso.xpm",
		&img.width, &img.height);
	/*img.item = mlx_xpm_file_to_image(mlx, "./sprites/",
		&img.width, &img.height);*/
	/*img.exit = mlx_xpm_file_to_image(game.mlx, "./sprites", &img.width, &img.height)*/;
	return (img);	
}

void	load_images(t_game game, t_tile img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game.height)
	{

		while (x < game.width)
		{
			if (game.map[y][x] == '0')
				mlx_put_image_to_window(game.mlx, game.win, img.empty, x * 64, y * 64) ;
			if (game.map[y][x] == '1')
				mlx_put_image_to_window(game.mlx, game.win, img.wall, x * 64, y * 64);
			if (game.map[y][x] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, img.player, x * 64, y * 64);
			// if (game.map[y][x] == 'C')
			// 	mlx_put_image_to_window(game.mlx, game.win, img.item, x * 64, y * 64);
			// if (game.map[y][x] == 'E')
			// 	mlx_put_image_to_window(game.mlx, game.win, img.exit, x *64, y * 64);
			x++;
		}
	x = 0;
	y++;
	}
}