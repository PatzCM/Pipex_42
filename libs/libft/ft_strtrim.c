/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:23:36 by palexand          #+#    #+#             */
/*   Updated: 2024/10/24 21:58:23 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	int		start;

	start = 0;
	size = ft_strlen((char *)s1) - 1;
	while (ft_strchr((char *)set, s1[start]) && s1[start])
		start++;
	while (ft_strchr((char *)set, s1[size]) && s1[start])
		size--;
	return (ft_substr((char *)s1, start, size - start + 1));
}
/*
int	main(void)
{
	char s1[] = "aaaaaaaaabaonetwoabca";
	char set[] = "abc";
	printf("%s\n", ft_strtrim(s1, set));

	Logic: start at the beginning of the string and iterate until
the first character that is not in the set is found. 
	Then, start at the end of the string and iterate until 
the first character that is not in the set is found.
	Finally, return a substring from the start to the end.
}
*/
