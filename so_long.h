/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:49 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/20 19:29:24 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "./get_next_line_V2/get_next_line.h"

void	exit_error(char	**map);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr(const char *s, char c);
char	**create_map(char **map, char *line);
int		ft_count_lines(void);
char	*fill_map(char *src);
void	free_tab(char **tab);
void	print_tab(char **tab);
int		check_config(char **map);
int		count_tablines(char **tab);

#endif