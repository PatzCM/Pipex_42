/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:07:56 by palexand          #+#    #+#             */
/*   Updated: 2024/11/09 13:07:56 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// 19 is the maximum size of a hexadecimal number
// The value is cast to an unsigned long to avoid problems with negative numbers
// If the value is 0, the hexadecimal number is 0
// The hexadecimal number is converted to a string
// The last digit of the hexadecimal number is obtained 
// If the digit is less than 10, it is converted to a character from 0 to 9
// If the digit is greater than 10, it is converted to a character from a to f
// The value is divided by 16 to get the next digit 
// The start variable is used to remove the zeros from the left;
static char	*ft_conversion(unsigned long value, char *hexadecimal, int index);

int	ft_pointer_printf(void *hex)
{
	unsigned long		value;
	char				hexadecimal[19];
	int					index;

	if (hex == NULL)
		return (write(1, "(nil)", 5));
	value = (unsigned long)hex;
	index = 18;
	hexadecimal[0] = '0';
	hexadecimal[1] = 'x';
	hexadecimal[18] = '\0';
	if (value == 0)
	{
		hexadecimal[2] = '0';
		hexadecimal[3] = '\0';
	}
	else
	{
		ft_conversion(value, hexadecimal, index);
	}
	ft_putstr_fd(hexadecimal, 1);
	return (ft_strlen(hexadecimal));
}

static char	*ft_conversion(unsigned long value, char *hexadecimal, int index)
{
	int	i;
	int	start;
	int	digit;

	i = 2;
	while (value > 0)
	{
		digit = value % 16;
		if (digit < 10)
			hexadecimal[index--] = digit + '0';
		else
			hexadecimal[index--] = (digit - 10) + 'a';
		value = value / 16;
	}
	start = index + 1;
	i = 2;
	while (start < 19)
		hexadecimal[i++] = hexadecimal[start++];
	hexadecimal[i] = '\0';
	return (hexadecimal);
}
