/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:40:12 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/11 22:51:12 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (s == NULL)
		return (count);
	while (s[count])
		count++;
	return (count);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dest || !src || !size)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (src_len);
}

char	*ft_strdup(char *str)
{
	size_t	len;
	char	*new_str;

	if (!str)
		return (NULL);
	len = ft_strlen(str) + 1;
	new_str = malloc(len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, len);
	return (new_str);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (!dest || !src)
		return (0);
	if (size == 0 || size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;

	size_t total_len, (s1_len), (s2_len);
	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	new_str = malloc(total_len);
	if (!new_str)
		return (NULL);
	if (!s1 || !s2)
	{
		if (!s1)
			ft_strlcpy(new_str, s2, s2_len + 1);
		else
			ft_strlcpy(new_str, s1, s1_len + 1);
	}
	else
	{
		ft_strlcpy(new_str, s1, s1_len + 1);
		ft_strlcat(new_str, s2, total_len);
	}
	return (new_str);
}
