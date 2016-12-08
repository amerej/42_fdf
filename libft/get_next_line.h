/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 01:55:35 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/29 12:31:27 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE  256

typedef struct			s_fd
{
	int					fd;
	char				*tmp;
	struct s_fd			*next;
}						t_fd;

t_fd					*ft_manage_fd(t_fd **list, int fd);
int						ft_read_tmp(char **line, t_fd *list);
int						ft_read_fd(char **line, t_fd *list);
int						get_next_line(int const fd, char **line);
#endif
