/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:53:22 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/09 15:45:50 by mvicedo          ###   ########.fr       */
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

int	handle_key_press(int key_code, t_game *game, t_tile *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	//printf("%d\n", key_code);
	// if (key_code == KEY_ESC)
	// 	exit_game(game, x, y);
	if (key_code == KEY_W || key_code == KEY_UP)
		move_up(game, x, y, img);
	// if (key_code == KEY_S|| key_code == KEY_DOWN)
	// 	move_down(game, x, y);
	// if (key_code == KEY_A || key_code == KEY_LEFT)
	// 	move_left(game, x, y);
	// if (key_code == KEY_D || key_code == KEY_RIGHT)
	// 	move_right(game, x, y);
	return (0);
}

void	move_up(t_game *game, int x, int y, t_tile *img)
{
	img = NULL;
	printf("%p", img);
	while (y < game->height)
	{
		while (x < game->width)
		{
			printf("ici");
			if (game->map[y][x] == 'P')
			{
				if (game->map[y - 1][x] == 'E')
					//clear_game(game);
					printf("sortie");
				if (game->map[y - 1][x] != '1' || game->map[y - 1][x] != 'E')
				{
					game->map[y][x] = '0';
					game->map[y - 1][x] = 'P';
					//load_images(game, img);
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
}

//void	move_down(t_game game, )