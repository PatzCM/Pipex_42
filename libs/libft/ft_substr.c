/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:18:24 by palexand          #+#    #+#             */
/*   Updated: 2024/10/24 16:18:24 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	i = 0;
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - start < len)
		sub = malloc((ft_strlen(s) - start) + 1);
	else
		sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*int	main (void)*/
/*{*/
/*	char str[]= "Hello world!";*/
/*	int	start = 4;*/
/*	size_t length = 9;*/
/*	// ft_substr(str, start, length);*/
/*	printf("%s\n", ft_substr(str,start, length));*/
/*}*/
