/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:09:56 by galiza            #+#    #+#             */
/*   Updated: 2019/11/09 17:12:08 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		check_double(int **arr, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	sort_int_arr(&(arr), len);
	while (i < len - 1)
	{
		if (arr[i][0] == arr[i + 1][0])
			return (0);
		i++;
	}
	return (1);
}

int		check_max_int(char *str)
{
	int	cmp;

	if (*str == '-')
	{
		cmp = ft_atoi(str);
		if (cmp == 0 || !(ft_strcmp("-2147483649", str)))
			return (0);
	}
	else
	{
		cmp = ft_atoi(str);
		if (cmp < 0)
			return (0);
	}
	return (1);
}

t_stack	*valid_each_arg(char **av)
{
	int		i;
	int		j;
	t_stack *new_list;

	i = -1;
	j = 0;
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (!(ft_isdigit(av[i][j])))
			return (NULL);
		while (ft_isdigit(av[i][j]))
			j++;
		if (av[i][j] != '\0')
			return (NULL);
		if (j >= 10)
			if (!(check_max_int(av[i])))
				return (NULL);
	}
	new_list = make_list(av, i);
	return (new_list);
}

t_stack	*valid_arg(char **av)
{
	char	**tmp;
	t_stack	*new_stack;

	new_stack = NULL;
	tmp = ft_strsplit(*av, ' ');
	if (tmp)
		new_stack = valid_each_arg(tmp);
	free_arr(tmp);
	if (!(new_stack))
		return (NULL);
	return (new_stack);
}

t_ps	*validation(char **av)
{
	t_stack	*new_stack;
	t_ps	*my_s;

	if (!(new_stack = valid_arg(av)))
		return (NULL);
	my_s = make_struct(&new_stack);
	if (!(check_double(my_s->cpy_arg, my_s->len_sa)))
	{
		free_struct(my_s);
		return (NULL);
	}
	return (my_s);
}
