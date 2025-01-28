/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:07:44 by palexand          #+#    #+#             */
/*   Updated: 2024/10/21 15:07:46 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_bzero(void *s, size_t n);

int	main (void)
{
	void	*s;
	size_t	n = 5;
	memset(mem, 'e', 5);
	printf("%s", ft_bzero(mem, 5));
}
*/

void	ft_bzero(void *s, size_t n)
{
	int					i;
	char				*str;

	str = s;
	i = 0;
	while (n > 0)
	{
		str[i] = 0;
		i++;
		n--;
	}
}
