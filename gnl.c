/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galiza <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:22:32 by galiza            #+#    #+#             */
/*   Updated: 2019/11/17 15:50:51 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	line_finder(int fd, char **line, char **str)
{
	size_t	end;
	char	*tmp;

	end = 0;
	tmp = NULL;
	while (str[fd][end] != '\0' && str[fd][end] != '\n')
		end++;
	if (str[fd][end] == '\n')
	{
		*line = ft_strsub(str[fd], 0, end + 1);
		tmp = ft_strdup(&str[fd][end + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][end] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

static int	read_in_buf(char *buf, int fd, char **file_data)
{
	int		ret;
	char	*temp;

	temp = NULL;
	ret = 0;
	while ((ret = read(fd, buf, 5)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strjoin(file_data[fd], buf);
		free(file_data[fd]);
		file_data[fd] = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	char		buf[5 + 1];
	int			ret;
	static char	*file_data[10240];

	ret = 0;
	if (fd < 0 || line == NULL || (read(fd, buf, 0)) < 0)
		return (-1);
	if (!(file_data[fd]))
	{
		if (!(file_data[fd] = (char *)malloc(1 * sizeof(char *))))
			return (-1);
		file_data[fd][0] = '\0';
	}
	ret = read_in_buf(buf, fd, file_data);
	if (ret < 0)
		return (-1);
	if (ret == 0 && (file_data[fd] == NULL || file_data[fd][0] == '\0'))
	{
		ft_strdel(&(file_data[fd]));
		return (0);
	}
	return (line_finder(fd, line, file_data));
}
