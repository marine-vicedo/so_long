/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:20:02 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/14 15:51:23 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_images(t_game *game)
{
	if (!game->img.wall || !game->img.empty || !game->img.player
		|| !game->img.item || !game->img.exit)
	{
		if (game->img.wall)
			mlx_destroy_image(game->mlx, game->img.wall);
		if (game->img.empty)
			mlx_destroy_image(game->mlx, game->img.empty);
		if (game->img.player)
			mlx_destroy_image(game->mlx, game->img.player);
		if (game->img.item)
			mlx_destroy_image(game->mlx, game->img.item);
		if (game->img.exit)
			mlx_destroy_image(game->mlx, game->img.exit);
		exit_error_display(game);
	}
	return (0);
}

t_tile	images_path(t_game *game)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/crystalwall.xpm", &width, &height);
	game->img.empty = mlx_xpm_file_to_image(game->mlx, "./sprites/fond.xpm",
			&width, &height);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "./sprites/perso.xpm",
			&width, &height);
	game->img.item = mlx_xpm_file_to_image(game->mlx, "./sprites/gem.xpm",
			&width, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./sprites/door.xpm", &width, &height);
	return (game->img);
}

void	update_image_win(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.empty,
			x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall,
			x * 64, y * 64);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img.player,
			x * 64, y * 64);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.item,
			x * 64, y * 64);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			x * 64, y * 64);
}

void	load_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			update_image_win(game, x, y);
			x++;
		}
	y++;
	}
}
