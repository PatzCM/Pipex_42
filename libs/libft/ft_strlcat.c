/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:50:48 by palexand          #+#    #+#             */
/*   Updated: 2024/10/21 15:51:00 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//unsigned int	ft_strlen(char *str)
//{
//	unsigned int	i;
//
//	i = 0;
//	while (str[i] != '\0')
//		i++;
//	return (i);
//}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (size == 0 || size <= d)
		return (s + size);
	while (src[i] != '\0' && i < (size - d - 1))
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (s + d);
}
