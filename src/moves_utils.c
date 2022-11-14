/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:16:51 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/12 18:37:49 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_pos_player(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	display_moves_cnt(int moves_count)
{
	write(1, "number of movements : ", 23);
	ft_putnbr_fd(moves_count, 1);
	write(1, "\n", 1);
}
