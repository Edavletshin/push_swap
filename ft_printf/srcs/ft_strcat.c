/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 19:18:19 by galiza            #+#    #+#             */
/*   Updated: 2019/06/09 09:48:18 by pcorlys-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		i1;

	i = 0;
	i1 = 0;
	while (s1[i])
		i++;
	while (s2[i1])
		s1[i++] = s2[i1++];
	s1[i] = '\0';
	return (s1);
}
