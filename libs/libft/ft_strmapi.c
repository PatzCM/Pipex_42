/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:06:23 by palexand          #+#    #+#             */
/*   Updated: 2024/11/05 17:55:21 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Applies the function f to each character of the string passed as argument
//by giving its index as first argument to create a new string resulting
//from the successive applications of f.
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
/*
char	r_tolower(unsigned int i, char c)
{
	i = 0;
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	main (void)
{
	char *buff = "HELLO";
	char *buff2 = ft_strmapi(buff,r_tolower);
	printf("%s", buff2);
	free(buff2);
}
*/
