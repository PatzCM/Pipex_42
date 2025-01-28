/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:23:32 by palexand          #+#    #+#             */
/*   Updated: 2024/10/24 16:26:18 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
int		ft_toupper(int ch);
void	ft_putchar(char ch);
int main (void)
{
int		ch = '5';
printf("%c", ft_toupper(ch));
}
*/
int	ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch -= 32);
	else
		return (ch);
}
