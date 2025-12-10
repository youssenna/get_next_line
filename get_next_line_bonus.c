/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:10:13 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/10 16:50:42 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_new_line(char *str)
{
	int	i;

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
	int	i;

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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		sub = ft_strdup("");
		if (!sub)
			return (NULL);
		return (sub);
	}
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

char	*ft_get_line(char *buffer, char **static_var, int read_nb)
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
	static char	*str[1024];
	t_var		var;

	var.buff = malloc(BUFFER_SIZE + 1);
	if (!var.buff || BUFFER_SIZE <= 0 || fd < 0 || read(fd, var.buff, 0) < 0
		|| fd >= 1024)
		return (free(var.buff), NULL);
	var.read_nb = 1;
	while (var.read_nb > 0)
	{
		if (ft_check_new_line(str[fd]))
		{
			var.tmp = str[fd];
			str[fd] = ft_strdup(str[fd] + ft_check_new_line(str[fd]));
			return (free(var.buff), ft_while_n_line(var.tmp));
		}
		var.read_nb = read(fd, var.buff, BUFFER_SIZE);
		if (var.read_nb < 0)
			break ;
		var.buff[var.read_nb] = 0;
		var.tmp = ft_get_line(var.buff, &str[fd], var.read_nb);
		if (var.tmp)
			return (free(var.buff), var.tmp);
	}
	return (free(var.buff), NULL);
}
