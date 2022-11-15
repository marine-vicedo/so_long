/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:53:22 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/15 15:21:24 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game, int x, int y)
{
	find_pos_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y - 1][x] == 'C')
		game->item--;
	if (game->map[y - 1][x] != '1' && game->map[y - 1][x] != 'E')
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->moves_cnt++;
		display_moves_cnt(game->moves_cnt);
		load_images(game);
	}
	if (game->map[y - 1][x] == 'E' && game->item == 0)
	{
		game->moves_cnt++;
		display_moves_cnt(game->moves_cnt);
		ft_putstr_fd("YOU WIN !\n", 1);
		exit_game(game);
	}
}

void	move_down(t_game *game, int x, int y)
{
	find_pos_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y + 1][x] == 'C')
		game->item--;
	if (game->map[y + 1][x] != '1' && game->map[y + 1][x] != 'E')
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		game->moves_cnt++;
		display_moves_cnt(game->moves_cnt);
		load_images(game);
	}
	if (game->map[y + 1][x] == 'E' && game->item == 0)
	{
		game->moves_cnt++;
		display_moves_cnt(game->moves_cnt);
		ft_putstr_fd("YOU WIN !\n", 1);
		exit_game(game);
	}
}

void	move_left(t_game *game, int x, int y)
{
	find_pos_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y][x - 1] == 'C')
		game->item--;
	if (game->map[y][x - 1] != '1' && game->map[y][x - 1] != 'E')
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		game->moves_cnt++;
		display_moves_cnt(game->moves_cnt);
		load_images(game);
	}
	if (game->map[y][x - 1] == 'E' && game->item == 0)
	{
		game->moves_cnt++;
		display_moves_cnt(game->moves_cnt);
		ft_putstr_fd("YOU WIN !\n", 1);
		exit_game(game);
	}
}

void	move_right(t_game *game, int x, int y)
{
	find_pos_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y][x + 1] == 'C')
		game->item--;
	if (game->map[y][x + 1] != '1' && game->map[y][x + 1] != 'E')
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		game->moves_cnt++;
		display_moves_cnt(game->moves_cnt);
		load_images(game);
	}
	if (game->map[y][x + 1] == 'E' && game->item == 0)
	{	
		game->moves_cnt++;
		display_moves_cnt(game->moves_cnt);
		ft_putstr_fd("YOU WIN !\n", 1);
		exit_game(game);
	}
}
