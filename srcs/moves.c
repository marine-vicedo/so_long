/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:53:22 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/11 18:26:03 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A = 97
// W = 119
// S = 115
// D = 100

// UP = 65362
// LEFT = 65361
// DOWN = 65364
// RIGHT = 65363

//ESC = 65307

#include "so_long.h"

int	handle_key_press(int key_code, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	//printf("%d\n", key_code);
	if (key_code == KEY_ESC)
	{
		exit_game(game);
		mlx_loop_end(game->mlx);
	}
	if (key_code == KEY_W || key_code == KEY_UP)
	{
		printf("ici\n");
		move_up(game, x, y);
	}
	if (key_code == KEY_S|| key_code == KEY_DOWN)
		move_down(game, x, y);
	if (key_code == KEY_A || key_code == KEY_LEFT)
		move_left(game, x, y);
	if (key_code == KEY_D || key_code == KEY_RIGHT)
		move_right(game, x, y);
	return (0);
}

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
				break;
			}
			x++;
		}
		y++;
	}
}

void	move_up(t_game *game, int x, int y)
{
	find_pos_player(game);
	x = game->player.x;
	y = game->player.y;
	
	if (game->map[y - 1][x] == 'C')
	{
		game->item--;
		printf("item = %d\n", game->item);
	}
	if (game->map[y - 1][x] != '1' && game->map[y - 1][x] != 'E')
	{
		printf("up\n");
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->walk_cnt++;
		printf("%d\n", game->walk_cnt);
		load_images(game);
	}
	if (game->map[y - 1][x] == 'E' && game->item == 0)
	{
		printf("game win\n");
		exit_game(game);
	}
}

void	move_down(t_game *game, int x, int y)
{
	find_pos_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y + 1][x] == 'C')
	{
		game->item--;
		printf("item = %d\n", game->item);
	}
	if (game->map[y + 1][x] != '1' && game->map[y + 1][x] != 'E')
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		game->walk_cnt++;
		printf("%d\n", game->walk_cnt);
		load_images(game);
	}
	if (game->map[y + 1][x] == 'E' && game->item == 0)
	{
		printf("game win\n");
		exit_game(game);
	}
}

void	move_left(t_game *game, int x, int y)
{
	find_pos_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y][x - 1] == 'C')
	{
		game->item--;
		printf("item = %d\n", game->item);
	}
	if (game->map[y][x - 1] != '1' && game->map[y][x - 1] != 'E')
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		game->walk_cnt++;
		printf("%d\n", game->walk_cnt);
		load_images(game);
	}
	if (game->map[y][x - 1] == 'E' && game->item == 0)
	{
		printf("YOU WIN\n");
		exit_game(game);
	}
}

void	move_right(t_game *game, int x, int y)
{
	find_pos_player(game);
	x = game->player.x;
	y = game->player.y;
	if (game->map[y][x + 1] == 'C')
	{
		game->item--;
		printf("item = %d\n", game->item);
	}
	if (game->map[y][x + 1] != '1' && game->map[y][x + 1] != 'E')
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		game->walk_cnt++;
		printf("%d\n", game->walk_cnt);
		load_images(game);
	}
	if (game->map[y][x + 1] == 'E' && game->item == 0)
	{	
		printf("game win\n");
		exit_game(game);
	}
}