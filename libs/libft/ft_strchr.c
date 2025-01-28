/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:20:26 by palexand          #+#    #+#             */
/*   Updated: 2024/10/23 17:20:46 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main (void)*/
/*{	*/
/*	const char	s[]="Somewhere over the\n rainbow";*/
/*	int	c = '\n';*/
/*	printf("%s", ft_strchr(s, c));*/
/*}*/

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *) s);
}
