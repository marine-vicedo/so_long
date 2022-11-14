/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:50:29 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/11 18:23:53 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.empty);
	mlx_destroy_image(game->mlx, game->img.player);
	mlx_destroy_image(game->mlx, game->img.item);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_tab(game->map);
	free_tab(game->path);
	free(game);
	exit(0);
}
