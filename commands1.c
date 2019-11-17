/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 19:55:23 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 18:13:16 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_stack(t_stack **s)
{
	t_stack *first_elem;
	t_stack	*sec_elem;
	int		tmp;

	if (!(*s) || !((*s)->data) || (!(*s)->next))
		return ;
	else
	{
		first_elem = *s;
		sec_elem = (*s)->next;
		tmp = first_elem->data;
		first_elem->data = sec_elem->data;
		sec_elem->data = tmp;
	}
}

void	swap_swap(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
}

void	push(t_stack **add, t_stack **take)
{
	t_stack	*first_elem_t;

	if (*take != NULL)
	{
		first_elem_t = *take;
		*take = (*take)->next;
		first_elem_t->next = *add;
		*add = first_elem_t;
	}
}

int		check_command(char *line, t_ps *my_s)
{
	if (ft_strcmp(line, "sa\n") == 0)
		my_s->funk_one[0](&(my_s->stacks[0]));
	else if (ft_strcmp(line, "sb\n") == 0)
		my_s->funk_one[0](&(my_s->stacks[1]));
	else if (ft_strcmp(line, "ss\n") == 0)
		my_s->funk_two[0](&(my_s->stacks[0]), &(my_s->stacks[1]));
	else if (ft_strcmp(line, "pa\n") == 0)
		my_s->funk_two[1](&(my_s->stacks[0]), &(my_s->stacks[1]));
	else if (ft_strcmp(line, "pb\n") == 0)
		my_s->funk_two[1](&(my_s->stacks[1]), &(my_s->stacks[0]));
	else if (ft_strcmp(line, "ra\n") == 0)
		my_s->funk_one[1](&(my_s->stacks[0]));
	else if (ft_strcmp(line, "rb\n") == 0)
		my_s->funk_one[1](&(my_s->stacks[1]));
	else if (ft_strcmp(line, "rr\n") == 0)
		my_s->funk_two[2](&(my_s->stacks[0]), &(my_s->stacks[1]));
	else if (ft_strcmp(line, "rra\n") == 0)
		my_s->funk_one[2](&(my_s->stacks[0]));
	else if (ft_strcmp(line, "rrb\n") == 0)
		my_s->funk_one[2](&(my_s->stacks[1]));
	else if (ft_strcmp(line, "rrr\n") == 0)
		my_s->funk_two[3](&(my_s->stacks[0]), &(my_s->stacks[1]));
	else
		return (0);
	return (1);
}

void	apply_com(t_ps *my_s, char *buff)
{
	int ret;

	ret = 0;
	while ((ret = get_next_line(0, &buff)) > 0)
	{
		if (!(check_command(buff, my_s)) && ft_strcmp(buff, "start\n"))
		{
			ft_strdel(&buff);
			error(my_s);
		}
		if (my_s->d != 0 || (my_s->d != 0 && ft_strcmp(buff, "start\n") == 0))
			print_list_debug(my_s->stacks[0], my_s->stacks[1]);
		ft_strdel(&buff);
	}
	ft_strdel(&buff);
}
