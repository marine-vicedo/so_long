/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:18:52 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/28 18:27:11 by mvicedo          ###   ########.fr       */
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

int	check_parameters(int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("Error : no arg\n");
		return (1);
	}
	else if (argc >= 3)
	{
		printf("Error : the program can read only one file at once\n");
		return (1);
	}
	else
	{
		if (check_filename_ext(argv[1]) == 1)
			{
				printf("Filename extension is not valid\n");
				return (1);
			}
	}
	return (0);
}