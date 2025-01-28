/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:10:08 by palexand          #+#    #+#             */
/*   Updated: 2024/10/21 15:10:35 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int alpha)
{
	if ((alpha >= 'a' && alpha <= 'z')
		|| (alpha >= 'A' && alpha <= 'Z')
		|| (alpha >= '0' && alpha <= '9'))
		return (1);
	else
		return (0);
}
