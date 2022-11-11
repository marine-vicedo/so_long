/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinevicedo <marinevicedo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:26:59 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/10 13:03:52 by marineviced      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}*/

int	ft_strchr(char *s, char c)
{
	unsigned int    i;
	
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_strcpy(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;	
	}
	dest[i] = '\0';
	return (dest);
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

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*dest;

	i = 0;
	len = ft_strlen((char *)s);
	dest = (char *)malloc ((len + 1) * sizeof(char));
	if (dest == 0)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
			i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}*/
