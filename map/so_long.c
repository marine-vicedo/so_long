/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/31 20:11:58 by mvicedo          ###   ########.fr       */
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

char	**create_map(char **map, char *file, t_game game)
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
	game = copy_map_to_game(map, game);
	print_tab(game.map);
	game = init_path(game);
	print_tab(game.path);
	free_tab(map);
	free_tab(game.map);
	free_tab(game.path);
	return (0);
}