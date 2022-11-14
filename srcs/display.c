/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:43:57 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/14 15:21:42 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return ;
	game->img = images_path(game);
	error_images(game);
	game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64,
			"so_long");
	load_images(game);
	mlx_hook(game->win, 2, 1L << 0, &handle_key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 1L << 0, &exit_game, game);
	mlx_loop(game->mlx);
}
