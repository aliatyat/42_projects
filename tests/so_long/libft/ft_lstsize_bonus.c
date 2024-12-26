/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:51:42 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/03 19:21:52 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*
int main(void)
{
    t_list *head;
    t_list *second;
    t_list *third;

    
    head = ft_lstnew("first node");
    second = ft_lstnew("second node");
    third = ft_lstnew("thired node");

    
    head->next = second;
    second->next = third;

    
    int size = ft_lstsize(head);
    printf("number of node: %d\n", size);

    return 0;
}
*/
