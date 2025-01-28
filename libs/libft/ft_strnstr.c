/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:57:26 by palexand          #+#    #+#             */
/*   Updated: 2024/11/07 15:57:51 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *word, size_t len)
{
	size_t		i;
	int			b;

	b = 0;
	i = 0;
	if (!haystack && !word)
		return (NULL);
	if (word[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[b + i] == word[b] && haystack[b + i] != '\0' \
			&& (b + i) < len)
		{
			b++;
			if (word[b] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
		b = 0;
	}
	return (NULL);
}
/*
int	main (void)
{
	char *haystack = "lorem ipsum dolor sit amet";
	char *word = "dolor";
	size_t len = 15;
	printf("%s\n", ft_strnstr(haystack, word, len));
}
*/
