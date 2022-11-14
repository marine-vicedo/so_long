/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:18:52 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/14 20:13:06 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filename_ext(char	*file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (file[len] == 'r' && file[len - 1] == 'e' && file[len - 2] == 'b'
		&& file[len - 3] == '.')
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("Error : map's file is missing", 2);
		return (0);
	}
	else if (argc > 2)
	{
		ft_putstr_fd("Error : too many arguments", 2);
		return (0);
	}
	else
	{
		if (!check_filename_ext(argv[1]))
		{
			ft_putstr_fd("Error : map's file is not .ber", 2);
			return (0);
		}
	}
	return (1);
}
