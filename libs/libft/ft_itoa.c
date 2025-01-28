/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:07:56 by palexand          #+#    #+#             */
/*   Updated: 2024/10/31 17:08:30 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n);

char	*ft_itoa(int n)
{
	long	i;
	char	*str;
	int		end;

	i = n;
	str = malloc((sizeof(char)) * (end = ft_counter(n)) + 1);
	if (str == NULL)
		return (NULL);
	if (i == 0)
		return (str[0] = '0', str[1] = '\0', str);
	if (i < 0)
	{
		str[0] = '-';
		i *= -1;
	}
	str[end] = '\0';
	while (i > 0)
	{
		str[--end] = i % 10 + 48;
		i = i / 10;
	}
	return (str);
}

static int	ft_counter(int n)
{
	long	nb;
	int		i;

	i = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

/*
int	main(void)
{
	long	i = 0;
	printf("%s", ft_itoa(i));
}
*/
