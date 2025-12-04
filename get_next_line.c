/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:28:10 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/04 20:22:11 by yousenna         ###   ########.fr       */
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
			break;
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

char	*ft_return_if_line(t_var *var, int fd, char **str)
{
	var->check_new_line = ft_check_new_line(*str);
	if (var->check_new_line)
	{
			var->new_buffer = ft_strdup(*str);
			var->free_ptr = *str;
			*str = ft_strdup(*str + var->check_new_line);
			free(var->free_ptr);
			return (free(var->buffer), ft_while_n_line(var->new_buffer));
	}
	var->read_nb = read(fd, var->buffer, BUFFER_SIZE);
	if (var->read_nb > 0)
	{
		var->buffer[var->read_nb] = 0;
		if (*str && (var->i)++ == 1)
			var->new_buffer = ft_strjoin(var->new_buffer, *str);
		var->new_buffer = ft_strjoin(var->new_buffer, var->buffer);
		var->check_new_line = ft_check_new_line(var->new_buffer);
		if (var->check_new_line)
		{
			free(*str);
			*str = ft_substr(var->new_buffer, var->check_new_line, ft_strlen(var->new_buffer + var->check_new_line));
			return (free(var->buffer), ft_while_n_line(var->new_buffer));
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	t_var	var;
	char	*return_;
	static char	*str;

	var.buffer = malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(0, var.buffer, 0) < 0)
		return (free(var.buffer), NULL);
	if (!var.buffer)
		return (NULL);
	var.i = 1;
	var.new_buffer = NULL;
	while (1)
	{
		return_ = ft_return_if_line(&var, fd, &str);
		if (return_ && var.read_nb > 0)
			return (return_);
		else if ((var.new_buffer && var.read_nb != 0))
			return (free(var.buffer), var.new_buffer);
		else
			break;
	}
	if ((var.new_buffer && var.read_nb != 0))
			return (free(var.buffer), var.new_buffer);
	return (free(str), free(var.buffer), NULL);
}


