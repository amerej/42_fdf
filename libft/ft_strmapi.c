/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 18:04:37 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/10 10:03:20 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = NULL;
	if (s)
		ret = (char *)malloc(sizeof(*ret) * (ft_strlen(s) + 1));
	if (ret && s && f)
	{
		while (s[i])
		{
			ret[i] = (*f)(i, (char)(s[i]));
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
