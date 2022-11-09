/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:43:57 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/09 15:16:51 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_path(t_game *game, t_tile *img)
{
	img->width = 64;
	img->height = 64;
	
	img->wall = mlx_xpm_file_to_image(game->mlx, "../sprites/Image0016.xpm",
		&img->width, &img->height);
	img->empty = mlx_xpm_file_to_image(game->mlx, "../sprites/fond.xpm",
		&img->width, &img->height);
	img->player = mlx_xpm_file_to_image(game->mlx, "../sprites/perso.xpm",
		&img->width, &img->height);
	/*img.item = mlx_xpm_file_to_image(mlx, "./sprites/",
		&img.width, &img.height);*/
	/*img.exit = mlx_xpm_file_to_image(game.mlx, "./sprites", &img.width, &img.height)*/;
}

void	load_images(t_game *game, t_tile *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->height)
	{
		while (x < game->width)
		{
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, img->empty, x * 64, y * 64) ;
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, img->wall, x * 64, y * 64);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, img->player, x * 64, y * 64);
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

void	display_game(t_game *game, t_tile *img)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return;	
	game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64,
		"so_long");
	images_path(game, img);
	load_images(game, img);
	mlx_hook(game->win, 2, 1L<<0, &handle_key_press, game);
	mlx_loop(game->mlx);
}