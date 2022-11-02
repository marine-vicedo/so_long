/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:18 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/02 14:05:23 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	path_finding(t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game = init_path(game, x, y);
	check_valid_path(game, x, y);
	return (game);
}

t_game	map_values(char *file, t_game game)
{
	int 	fd;
	char	*line;
	
	fd = open(file, O_RDONLY);
	printf("fd is %d\n", fd);
	if (fd < 0)
		exit(0);
	line = get_next_line(fd);
	game.width = ft_strlen(line) - 1;
	game.height = ft_count_lines(file);
	free (line);
	close(fd);
	return (game);
}