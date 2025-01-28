/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:09:25 by palexand          #+#    #+#             */
/*   Updated: 2024/10/22 18:35:36 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
void	*ft_memcpy(void *dest_str, const void * src_str, size_t n);

int	main (void)
{
	
	char src_str[]="Soon in Common Core";
	size_t n = ft_strlen(src_str);
	char dest_str[n];
	printf("%p", ft_memcpy(src_str, dest_str, n));
}
*/
// The memcpy() copies n bytes from memory area src to memory area dest.
void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	unsigned char			*dest;
	unsigned char			*src;
	size_t					i;

	i = 0;
	dest = (unsigned char *)dest_str;
	src = (unsigned char *)src_str;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
