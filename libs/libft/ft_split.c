/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:11:55 by palexand          #+#    #+#             */
/*   Updated: 2024/10/28 16:11:55 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char *s, char c);
static void	ft_free(char **s);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		b;
	int		start;
	char	**substring;

	substring = malloc((ft_countwords((char *)s, c) + 1) * sizeof(char *));
	if (!substring)
		return (NULL);
	i = 0;
	b = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (start < i)
		{
			substring[b] = ft_substr(s, start, i - start);
			if (substring[b++] == NULL)
				return (ft_free(substring), NULL);
		}
	}
	return (substring[b] = NULL, substring);
}

static int	ft_countwords(char *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}
/*
int	main(void)
{
	char	str[] = "       lorem    ipsum dolor sit amet, consectetu";
	char	sep = ' ';
	char	**s = ft_split(str, sep);
	int	i = 0;

	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
}
*/
