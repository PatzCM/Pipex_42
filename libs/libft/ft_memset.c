/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:19:22 by palexand          #+#    #+#             */
/*   Updated: 2024/10/23 17:19:30 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
void	*ft_memset(void *s, int c, size_t n);

int	main (void)
{
	char str[] = "Hello little world";
	int	size = 8;
	char	value = '.';
	printf("Original: %p\n", ft_memset(str, value, size));
	printf("String: %s\n", str);
	printf("Function: %p\n", memset(str, value, size));
}
*/
// The memset() writes n bytes of value c 
// (converted to an unsigned char) to the string s.

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
