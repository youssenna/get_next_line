/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 16:40:47 by yousenna          #+#    #+#             */
/*   Updated: 2025/12/10 15:48:02 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_var
{
	int		read_nb;
	char	*buff;
	char	*tmp;
}			t_var;

char		*get_next_line(int fd);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_strlen(const char *s);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_get_line(char *buffer, char **static_var, int read_nb);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_while_n_line(char *str);
int			ft_check_new_line(char *str);

#endif
