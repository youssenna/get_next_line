/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:28:10 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/04 13:21:34 by yousenna         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

char	*get_next_line(int fd)
{
	static char	*str;

	char *buffer, (*new_buffer), (*free_ptr);
	int read_nb, (check_new_line), i;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(0, buffer, 0) < 0)
		return (NULL);
	i = 1;
	new_buffer = NULL;
	while (1)
	{
		check_new_line = ft_check_new_line(str);
		if (check_new_line)
		{
				new_buffer = ft_strdup(str);
				free_ptr = str;
				str = ft_strdup(str + check_new_line);
				free(free_ptr);
				return (ft_while_n_line(new_buffer));
		}
		read_nb = read(fd, buffer, BUFFER_SIZE);
		if (read_nb > 0)
		{
			buffer[read_nb] = 0;
			if (str && i++ == 1)
				new_buffer = ft_strjoin(new_buffer, str);
			new_buffer = ft_strjoin(new_buffer, buffer);
			check_new_line = ft_check_new_line(new_buffer);
			if (check_new_line)
			{
				free_ptr = new_buffer;
				new_buffer = ft_strdup(new_buffer);
				free(free_ptr);
				str = ft_substr(new_buffer, check_new_line, ft_strlen(new_buffer + check_new_line));
				return (ft_while_n_line(new_buffer));
			}
		}
		else if (new_buffer && read_nb != 0)
			return (new_buffer);
		else
			break;
	}
	if (new_buffer != NULL)
		return (new_buffer);
	return (free(str), NULL);
}


