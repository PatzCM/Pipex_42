/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:24:49 by palexand          #+#    #+#             */
/*   Updated: 2024/10/24 15:24:49 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	main(void)*/
/*{*/
/*	const char s[]="Somewhere\n over the rainbow \n high";*/
/*	int	c = '\n';*/
/*	printf("Mine:%s\n", ft_strrchr(s, c));*/
/*	printf("Original:%s", strrchr(s, c));*/
/*}*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
