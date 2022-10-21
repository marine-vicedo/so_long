/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:00 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/21 15:36:26 by mvicedo          ###   ########.fr       */
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

int	ft_count_lines(void)
{
	char	*line;
	int		count;
	int		fd2;

	fd2 = open("../map1.ber", O_RDONLY);
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

char	**create_map(char **map, char *line)
{
	int		i;
	int		fd;
	int		tab_size;

	i = 0;
	tab_size = ft_count_lines();
	fd = open("../map1.ber", O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (tab_size + 1));
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
	close (fd);
	return (map);
}

int	main(void)
{
	char	**map;
	char	*line;

	line = NULL;
	map = NULL;
	map = create_map(map, line);
	if (check_config(map) == 0)
		exit_error(map);
	print_tab(map);
	free_tab(map);
	return (0);
}