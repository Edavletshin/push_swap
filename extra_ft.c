/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:59:51 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 17:58:06 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		is_sort(t_stack *list)
{
	if (list)
	{
		while (list->next)
		{
			if (list->data >= list->next->data)
				return (0);
			list = list->next;
		}
	}
	return (1);
}

void	sort_int_arr(int ***arr, int len)
{
	int i;
	int i1;
	int box;

	i = 0;
	i1 = 0;
	while (i < len)
	{
		i1 = 0;
		while (i1 < len - 1)
		{
			if ((*arr)[i1][0] > (*arr)[i1 + 1][0])
			{
				box = (*arr)[i1][0];
				(*arr)[i1][0] = (*arr)[i1 + 1][0];
				(*arr)[i1 + 1][0] = box;
				box = (*arr)[i1][1];
				(*arr)[i1][1] = (*arr)[i1 + 1][1];
				(*arr)[i1 + 1][1] = box;
			}
			i1++;
		}
		i++;
	}
}

void	sort_list(t_stack *list)
{
	t_stack	*tmp;
	t_stack	*c_elem;

	tmp = list;
	while (tmp)
	{
		c_elem = tmp;
		while (c_elem)
		{
			if (c_elem->next != NULL && c_elem->data > c_elem->next->data)
				swap_stack(&c_elem);
			c_elem = c_elem->next;
		}
		tmp = tmp->next;
	}
}

int		find_min(t_stack *stack)
{
	t_stack	*start;
	int		min;
	int		nbr;

	start = stack;
	min = 2147483647;
	nbr = -1;
	while (start)
	{
		if (start->way < min)
		{
			min = start->way;
			nbr = start->number;
		}
		start = start->next;
	}
	return (nbr);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack *max;

	max = stack;
	while (stack)
	{
		if (max->data < stack->data)
		{
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}
