/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:10:26 by palexand          #+#    #+#             */
/*   Updated: 2024/11/05 18:11:01 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void	r_tolower(unsigned int i, char *s)
{
	i = 0;
	s[0] += 32;
}

int	main (void)
{
	char buff[] = "HELLOWORLD";
	ft_striteri(buff, r_tolower);
	printf("%s", buff);
}
*/
