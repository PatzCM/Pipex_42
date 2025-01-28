/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:46:17 by palexand          #+#    #+#             */
/*   Updated: 2024/10/21 15:46:19 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
void	*ft_memmove(void *dest, const void *src, size_t n);
int	main (void)
{
	char	dest[]="";
	const char src[]="Hello";
	size_t n = 5;
	ft_memmove(dest, src, n);
}
*/
// The memmove() copies n bytes from memory area src to memory area dest. 
// The memory areas may overlap: copying takes place as though the bytes in src
// are first copied into a temporary array that does not overlap src or dest, 
// and the bytes are then copied from the temporary array to dest.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ddest;
	unsigned char		*ssrc;

	ddest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	i = 0;
	if (ddest > ssrc)
	{
		while (i++ < n)
			ddest[n - i] = ssrc[n - i];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
