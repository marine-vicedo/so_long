/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:43:57 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/12 17:49:12 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	images_path(t_game *game)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"../sprites/crystal-wall.xpm", &width, &height);
	game->img.empty = mlx_xpm_file_to_image(game->mlx, "../sprites/fond.xpm",
			&width, &height);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "../sprites/perso.xpm",
			&width, &height);
	game->img.item = mlx_xpm_file_to_image(game->mlx, "../sprites/gem.xpm",
			&width, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"../sprites/door.xpm", &width, &height);
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

void	display_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return ;
	game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64,
			"so_long");
	game->img = images_path(game);
	load_images(game);
	mlx_hook(game->win, 2, 1L << 0, &handle_key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1L << 0, &exit_game, game);
	mlx_loop(game->mlx);
}
