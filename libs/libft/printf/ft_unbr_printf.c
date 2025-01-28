/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:16:41 by palexand          #+#    #+#             */
/*   Updated: 2024/11/09 15:20:43 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_unbr_printf(unsigned int nr)
{
	int	len;

	len = 0;
	if (nr >= 10)
	{
		len += ft_unbr_printf(nr / 10);
		nr = nr % 10;
	}
	if (nr < 10)
		ft_putchar_fd(nr + '0', 1);
	return (len + 1);
}
