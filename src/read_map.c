/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:10:56 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/15 15:22:20 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*fill_map(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	while (src[i] != '\0' && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_count_lines(char *file)
{
	char	*line;
	int		count;
	int		fd2;

	count = 0;
	fd2 = open(file, O_RDONLY);
	if (fd2 < 0)
		exit(0);
	line = get_next_line(fd2);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd2);
	}
	close(fd2);
	return (count);
}

void	read_map(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(game, 0);
	line = NULL;
	line = get_next_line(fd);
	if (!line)
		exit_error(game, 1);
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return ;
	while (line)
	{
		game->map[i] = fill_map(line);
		i++;
		free (line);
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	free(line);
	close (fd);
}
