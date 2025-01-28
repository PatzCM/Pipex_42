/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:14:11 by palexand          #+#    #+#             */
/*   Updated: 2024/11/06 17:14:11 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int			counter;
	t_list		*temp;

	counter = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}
