/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:46:08 by palexand          #+#    #+#             */
/*   Updated: 2024/11/20 15:46:11 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*left_trim(char *left_c)
{
	int		i;
	int		k;
	char	*temp;

	i = 0;
	while (left_c[i] && left_c[i] != '\n')
		i++;
	if (!left_c[i])
	{
		free(left_c);
		return (NULL);
	}
	temp = ft_calloc((ft_strlen(left_c) - i + 1), sizeof(char));
	if (!temp)
		return (NULL);
	k = 0;
	while (left_c[i++])
		temp[k++] = left_c[i];
	temp[k] = '\0';
	free(left_c);
	return (temp);
}

/*void	*ft_calloc(size_t nbytes, size_t size)*/
/*{*/
/*	size_t			i;*/
/*	unsigned char	*str;*/
/**/
/*	str = malloc(nbytes * size);*/
/*	if (!str)*/
/*		return (0);*/
/*	i = 0;*/
/*	while (i < (nbytes * size))*/
/*		str[i++] = '\0';*/
/*	return (str);*/
/*}*/
