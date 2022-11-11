/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinevicedo <marinevicedo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:54 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/10 13:17:52 by marineviced      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*static void	ft_print(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
	{
		write(1, &tab[i], 1);
		i++;
	}
}*/

void	print_tab(char **tab)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			write(1, &tab[i][j], 1);
			j++;	
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

