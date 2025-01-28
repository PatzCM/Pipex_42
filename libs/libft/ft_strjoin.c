/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:27:15 by palexand          #+#    #+#             */
/*   Updated: 2024/10/24 18:27:15 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s1) + ft_strlen(s2) == 0)
	{
		free(s1);
		return (NULL);
	}
	result = ft_calloc((ft_strlen(s1)+ft_strlen(s2) + 1), sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	free(s1);
	return (result);
}
/*
int	main(void)
{
	char s1[] = "test";
	char s2[] = "this time";
	printf("Mine: %s\n", ft_strjoin(s1, s2));
	//printf("Original: %d\n", strjoin(s1, s2));
}
*/
