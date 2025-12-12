/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:28:10 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/11 22:57:10 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_check_new_line(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_while_n_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i + 1] = 0;
			break ;
		}
		i++;
	}
	return (str);
}

char	*ft_get_line(char *buffer, char **static_var, ssize_t read_nb)
{
	char	*tmp;

	tmp = ft_strjoin(*static_var, buffer);
	if (ft_check_new_line(tmp))
	{
		free(*static_var);
		*static_var = ft_strdup(tmp + ft_check_new_line(tmp));
		return (ft_while_n_line(tmp));
	}
	else if (read_nb < BUFFER_SIZE)
	{
		free(*static_var);
		*static_var = NULL;
		if (tmp && *tmp)
			return (tmp);
		return (free(tmp), NULL);
	}
	else if (tmp)
	{
		free(*static_var);
		*static_var = ft_strdup(tmp);
		return (free(tmp), NULL);
	}
	return (free(tmp), NULL);
}

char	*get_next_line(int fd)
{
	static char	*str;
	t_var		var;

	var.total_len = (size_t)BUFFER_SIZE + 1;
	var.buff = malloc(var.total_len);
	if (!var.buff || BUFFER_SIZE <= 0 || fd < 0)
		return (free(var.buff), NULL);
	var.read_nb = 1;
	while (var.read_nb > 0)
	{
		if (ft_check_new_line(str))
		{
			var.tmp = str;
			str = ft_strdup(str + ft_check_new_line(str));
			return (free(var.buff), ft_while_n_line(var.tmp));
		}
		var.read_nb = read(fd, var.buff, BUFFER_SIZE);
		if (var.read_nb < 0)
			return (free(var.buff), NULL);
		var.buff[var.read_nb] = 0;
		var.tmp = ft_get_line(var.buff, &str, var.read_nb);
		if (var.tmp)
			return (free(var.buff), var.tmp);
	}
	return (free(var.buff), NULL);
}
