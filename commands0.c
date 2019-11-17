/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:55:13 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 18:12:18 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*first_elem;
	t_stack	*penult;

	if (!(*s) || !((*s)->next))
		return ;
	first_elem = (*s)->next;
	penult = first_elem;
	(*s)->next = NULL;
	while (penult->next)
		penult = penult->next;
	penult->next = *s;
	*s = first_elem;
}

void	rotate_twice(t_stack **a, t_stack **b)
{
	if (*a)
		rotate(a);
	if (*b)
		rotate(b);
}

void	rev_rotate(t_stack **s)
{
	t_stack *end;
	t_stack	*penult;

	if (!(*s) || !((*s)->next))
		return ;
	end = *s;
	while (end->next->next)
		end = end->next;
	penult = end;
	end = end->next;
	penult->next = NULL;
	end->next = *s;
	*s = end;
}

void	rev_rotate_twice(t_stack **a, t_stack **b)
{
	if (*a)
		rev_rotate(a);
	if (*b)
		rev_rotate(b);
}

void	error(t_ps *my_s)
{
	ft_putstr_fd("Error\n", 2);
	free_struct(my_s);
	exit(0);
}
