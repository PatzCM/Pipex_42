/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:56:15 by palexand          #+#    #+#             */
/*   Updated: 2024/11/09 12:56:17 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <limits.h>
#define MIN_INT -2147483648

static int	ft_args(va_list args, char var_type);

int	ft_printf(const char *argument, ...)
{
	int		counter;
	int		i;
	va_list	args;

	va_start(args, argument);
	i = -1;
	counter = 0;
	while (argument[++i])
	{
		if (argument[i] == '%')
			counter += ft_args(args, argument[++i]);
		else
		{
			write(1, &argument[i], 1);
			counter++;
		}
	}
	va_end(args);
	return (counter);
}

static int	ft_args(va_list args, char var_type)
{
	if (var_type == 's')
		return (ft_str_printf(va_arg(args, char *)));
	if (var_type == 'i')
		return (ft_nbr_printf(va_arg(args, int)));
	if (var_type == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (var_type == 'p')
		return (ft_pointer_printf(va_arg(args, void *)));
	if (var_type == 'd')
		return (ft_nbr_printf(va_arg(args, int)));
	if (var_type == 'u')
		return (ft_unbr_printf(va_arg(args, unsigned int)));
	if (var_type == 'x')
		return (ft_hexa_printf(va_arg(args, unsigned int), 0));
	if (var_type == 'X')
		return (ft_hexa_printf(va_arg(args, unsigned int), 1));
	if (var_type == '%')
		ft_putchar_fd('%', 1);
	if (var_type == '%' || var_type == 'c')
		return (1);
	else
		return (0);
}
