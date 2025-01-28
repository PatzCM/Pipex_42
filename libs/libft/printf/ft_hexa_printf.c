/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:07:01 by palexand          #+#    #+#             */
/*   Updated: 2024/11/09 13:07:01 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_hexa_printf(unsigned int n, int upper_or_lower)
{
	char	*base;
	char	digit[9];
	int		i;
	int		len;

	i = 0;
	if (upper_or_lower == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		digit[i++] = base[n % 16];
		n = n / 16;
	}
	len = i;
	while (--i >= 0)
	{
		ft_putchar_fd(digit[i], 1);
	}
	return (len);
}
