/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:54 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/12 17:29:54 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_tab(char **tab)
{
	int	i;
	int	j;

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

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{	
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar_fd((n + '0'), fd);
	else
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
}
