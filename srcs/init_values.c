/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:58:18 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/11 18:16:37 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_values(char *file, t_game *game)
{
	int 	fd;
	char	*line;
	
	fd = open(file, O_RDONLY);
	printf("fd is %d\n", fd);
	if (fd < 0)
		exit(0);
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	game->height = ft_count_lines(file);
	game->map = NULL;
	game->path = NULL;
	game->walk_cnt = 0;
	free (line);
	close(fd);
	//return (game);
}