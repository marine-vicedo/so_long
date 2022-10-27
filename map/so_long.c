/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/27 18:59:40 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* seg fault with t_game *game but not with t_game game*/

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
	line = get_next_line(fd2);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd2);
	}
	close(fd2);
	//printf("ft count lines %d\n", count);
	return (count);
}

char	**create_map(char **map, char *file, t_game game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
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
	printf("i is %d\n", i);
	map[i] = NULL;
	close (fd);
	return (map);
}

t_game	map_values(char *file, t_game game)
{
	int 	fd;
	char	*line;
	
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	game.width = ft_strlen(line) - 1;
	game.height = ft_count_lines(file);
	game.x = 0;
	game.y = 0;
	free (line);
	close(fd);
	return (game);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	map = NULL;
	if (check_parameters(argc, argv) == 1)
	{
		printf("Parameters invalid\n");
		return (0);
	}
	game = map_values(argv[1], game);
	map = create_map(map, argv[1], game);
	printf("width value %d\n", game.width);
	printf("heigt value %d\n", game.height);
	if (check_config(map, game) == 0)
		exit_error(map);
	print_tab(map);
	free_tab(map);
	return (0);
}