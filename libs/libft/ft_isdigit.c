/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:02:31 by palexand          #+#    #+#             */
/*   Updated: 2024/10/21 15:02:35 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
#include <stdio.h>
#include <ctype.h>
int	ft_isdigit (int a);

int	main (void)
{
int	a = '-';
printf("original:%i\n", isdigit(a));
printf("mine:%i\n", ft_isdigit(a));
}
*/
int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (a);
	else
		return (0);
}
