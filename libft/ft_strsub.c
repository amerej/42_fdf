/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 00:58:30 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/09 11:03:23 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(*ret) * (n + 1));
	if (ret && s)
	{
		while (i < n)
		{
			ret[i] = s[start + i];
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
