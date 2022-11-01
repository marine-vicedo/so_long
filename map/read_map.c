/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:10:56 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/01 12:10:59 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*fill_map(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i] != '\n')
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
	//printf("ft count lines %d\n", count);
	//if count == 0 pas de lignes -> file vide, a rajouter
	return (count);
}

char	**read_map(char **map, char *file, t_game game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(map);
	line = NULL;
	map = (char **)malloc(sizeof(char *) * (game.height + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = fill_map(line);
		i++;
		free (line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	free(line);
	close (fd);
	return (map);
}