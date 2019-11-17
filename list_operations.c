/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:04:52 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 17:58:21 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_list_debug(t_stack *a, t_stack *b)
{
	ft_printf("~---- A ----~ | ~---- B ----~\n");
	while (a || b)
	{
		if (a && b)
		{
			ft_printf("~%6d     ~ | ~%6d     ~\n", a->data, b->data);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			ft_printf("~%6d     ~ | ~           ~\n", a->data);
			a = a->next;
		}
		else if (b && !a)
		{
			ft_printf("~           ~ | ~%6d     ~\n", b->data);
			b = b->next;
		}
	}
	ft_printf("~-----------~ | ~-----------~\n");
}

t_stack	*make_list(char **av, int ac)
{
	t_stack	*start;
	t_stack	*begin_tmp;
	t_stack	*tmp;
	int		i;

	i = 0;
	start = make_instance_of_struct(ft_atoi(av[0]), i);
	begin_tmp = start;
	while (i++ < ac - 1)
	{
		if (av[i][0] != '\0')
		{
			tmp = make_instance_of_struct(ft_atoi(av[i]), i);
			begin_tmp->next = tmp;
			begin_tmp = begin_tmp->next;
			tmp = NULL;
		}
	}
	return (start);
}

void	numeric_lst(t_stack **list)
{
	t_stack	*a;
	int		i;

	a = *list;
	i = 1;
	while (a)
	{
		a->number = i;
		i++;
		a = a->next;
	}
}

int		**cpy_list_ar(t_stack *list, int len)
{
	int		**arr;
	int		i;

	i = 0;
	if (!list)
		return (NULL);
	if (!(arr = (int **)malloc(sizeof(int*) * len + 1)))
	{
		free_lst(&list);
		exit(1);
	}
	while (i < len)
	{
		if (!(arr[i] = (int *)malloc(sizeof(int) * 2)))
		{
			free_lst(&list);
			free_int_arr(arr, i);
			exit(1);
		}
		arr[i][0] = list->data;
		arr[i++][1] = list->number;
		list = list->next;
	}
	return (arr);
}

void	free_lst(t_stack **s)
{
	t_stack *tmp;
	t_stack *tmp1;

	if (*s)
	{
		tmp = *s;
		while (tmp)
		{
			tmp1 = tmp->next;
			free(tmp);
			tmp = tmp1;
		}
		*s = NULL;
	}
}
