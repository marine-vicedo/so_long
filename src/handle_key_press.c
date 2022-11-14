/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:32:38 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/12 18:36:48 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key_press(int key_code, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key_code == KEY_ESC)
	{
		exit_game(game);
		mlx_loop_end(game->mlx);
	}
	if (key_code == KEY_W || key_code == KEY_UP)
		move_up(game, x, y);
	if (key_code == KEY_S || key_code == KEY_DOWN)
		move_down(game, x, y);
	if (key_code == KEY_A || key_code == KEY_LEFT)
		move_left(game, x, y);
	if (key_code == KEY_D || key_code == KEY_RIGHT)
		move_right(game, x, y);
	return (0);
}
