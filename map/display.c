/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:43:57 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/02 18:29:09 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	images_ID(void *mlx, t_game game)
{
	game.wall = mlx_xpm_file_to_image(mlx, "./sprites/Image0016.xpm",
		&game.wall.width, &game.wall.height);
}
