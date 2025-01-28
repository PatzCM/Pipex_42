/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palexand <palexand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:23:16 by palexand          #+#    #+#             */
/*   Updated: 2024/11/06 17:23:16 by palexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*We want to create a new list with the content of the first list */
/*after applying the function f to each element of the list.*/
/*If the list is empty or the f or del is NULL, we return NULL.*/
/*We go through the list and apply the function f to each element of the list.*/
/*If the function f fails, we delete the new list and the content of the node.*/
/*We add the new node to the new list.*/
/**/
t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*tmp;
	t_list	*node_content;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		tmp = (f)(lst->content);
		node_content = ft_lstnew(tmp);
		if (node_content == NULL)
		{
			ft_lstclear(&new_list, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node_content);
		lst = lst->next;
	}
	return (new_list);
}
