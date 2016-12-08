/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 01:26:00 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/05 13:47:48 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (n == 0)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, n));
	n--;
	while (n > 0)
	{
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		n--;
	}
	((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	return (dst);
}
