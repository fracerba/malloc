/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracerba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:15:54 by fracerba          #+#    #+#             */
/*   Updated: 2022/10/21 15:15:56 by fracerba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_lst(t_list *l, void *(*f)(void *), void (*d)(void *), t_list *n)
{
	n -> content = malloc(sizeof(l -> content));
	if (!n -> content)
		return (0);
	n -> content = ((*f)(l -> content));
	n -> next = malloc(sizeof(t_list));
	if (!n -> next)
	{
		ft_lstclear(&n, d);
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	temp = new;
	while (lst && lst -> content)
	{
		if (!ft_lst(lst, f, del, new))
			return (0);
		lst = lst -> next;
		if (lst != 0)
			new = new -> next;
	}
	free(new -> next);
	new -> next = 0;
	return (temp);
}
