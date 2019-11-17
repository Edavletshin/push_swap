/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:08:47 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 17:56:43 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		lstsize_test(t_stack *begin_list)
{
	int		i;
	t_stack	*temp;

	if (!begin_list)
		return (0);
	i = 0;
	temp = begin_list;
	while (temp != 0)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_stack	*make_instance_of_struct(int data, int num)
{
	t_stack	*new_elem;

	new_elem = (t_stack *)malloc(sizeof(t_stack));
	new_elem->data = data;
	new_elem->number = num;
	new_elem->near_left = -1;
	new_elem->next = NULL;
	return (new_elem);
}

t_ps	*make_struct(t_stack **s_a)
{
	t_ps	*my_s;

	if (!(my_s = (t_ps *)malloc(sizeof(t_ps))))
	{
		free_lst(s_a);
		exit(1);
	}
	my_s->funk_one[0] = &swap_stack;
	my_s->funk_one[1] = &rotate;
	my_s->funk_one[2] = &rev_rotate;
	my_s->funk_two[0] = &swap_swap;
	my_s->funk_two[1] = &push;
	my_s->funk_two[2] = &rotate_twice;
	my_s->funk_two[3] = &rev_rotate_twice;
	my_s->stacks[0] = *s_a;
	my_s->stacks[1] = NULL;
	my_s->len_sa = lstsize_test(*s_a);
	my_s->len_sb = 0;
	if (!(my_s->cpy_arg = cpy_list_ar(*s_a, my_s->len_sa)))
	{
		free_lst(&(my_s->stacks[0]));
		free(my_s);
		exit(1);
	}
	return (my_s);
}

void	free_int_arr(int **arr, int len)
{
	int i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_struct(t_ps *my_s)
{
	if (my_s)
	{
		free_lst(&(my_s->stacks[0]));
		free_lst(&(my_s->stacks[1]));
		free_int_arr(my_s->cpy_arg, my_s->len_sa);
		free(my_s);
		my_s = NULL;
	}
}
