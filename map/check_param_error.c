/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:18:52 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/09 16:25:48 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*checks if :
- there is no file (argc <= 1)
- there is more than 1 file (argc >= 3) : print a warning to tell the user
that only the 1st parameter will be considered
- the filename extension is valid : it must be a .ber file.
- check if is not a folder
*/

int	check_filename_ext(char	*file)
{
	int	len;

	len = ft_strlen(file) - 1;

	if (file[len] == 'r' && file[len - 1] == 'e' && file[len - 2] == 'b'
		&& file[len - 3] == '.')
		return (0);
	else
		return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc <= 1)
	{
		ft_putstr_fd("Error : you must provide a file", 2);
		return (0);
	}
	else if (argc >= 3)
	{
		ft_putstr_fd("Error : the program can read only one file at once", 2);
		return (0);
	}
	else
	{
		if (check_filename_ext(argv[1]) == 1)
		{
			ft_putstr_fd("Filename extension is not valid", 2);
			return (0);
		}
	}
	return (1);
}