/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/01 16:28:47 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* seg fault with t_game *game but not with t_game game*/

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
	map = read_map(map, argv[1], game);
	printf("width value %d\n", game.width);
	printf("heigt value %d\n", game.height);
	if (check_config(map, game) == 0)
		exit_error(map);
	game = copy_map_to_game(map, game);
	game = path_finding(game);
	print_tab(game.map);
	write(1, "\n", 1);
	print_tab(game.path);
	free_tab(map);
	free_tab(game.map);
	free_tab(game.path);
	return (0);
}