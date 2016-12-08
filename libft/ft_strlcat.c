/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 01:27:40 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/09 10:51:14 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	dst_size;

	count = 0;
	dst_size = ft_strlen(dst);
	if (size <= dst_size)
		return (ft_strlen(src) + size);
	while (src[count] && count < (size - dst_size - 1))
	{
		dst[dst_size + count] = src[count];
		count++;
	}
	dst[dst_size + count] = '\0';
	return (dst_size + ft_strlen(src));
}
