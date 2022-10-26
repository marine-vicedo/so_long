/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:18:52 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/26 17:25:35 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*checks if :
- there is no file (argc <= 1)
- there is more than 1 file (argc >= 3) : print a warning to tell the user that only the 1st parameter will be considered
- the filename extension is valid : the file does not be a hidden file, it must be a .ber file.
We check if the file suffix for the current and parent folder (if the file suffix is "./" or "../")
*/

int	check_filename_ext(char *file)
{
	int	i;

	i = 0;
	if (file && file[i] == '.')
	{
		if(file[i + 1] == '.' && file[i + 2] == '/')
			i = 2;
		else if (file[i + 1] == '/')
			i = 1;
		else
		{
			printf("Hidden file\n");
			return (1);
		}
	}
	while (file[i] != '.')
		i++;
	while (file)
	{
		if(file[i] == '.' && file[i + 1] == 'b' && file [i + 2] == 'e'
			&& file[i + 3] == 'r' && file[i + 4] == '\0')
			return (0);
		else
			return (1);
	}
	return (0);
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