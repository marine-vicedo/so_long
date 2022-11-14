/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:18 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/12 17:30:47 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_values(char *file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(game, 0);
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	game->height = ft_count_lines(file);
	game->map = NULL;
	game->path = NULL;
	game->moves_cnt = 0;
	free (line);
	close(fd);
}
