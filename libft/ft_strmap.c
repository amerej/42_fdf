/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 18:04:37 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/04 17:29:57 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			ret[i] = (*f)((char)(s[i]));
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
