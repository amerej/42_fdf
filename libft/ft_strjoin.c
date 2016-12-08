/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 01:28:01 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/05 14:03:59 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = NULL;
	if (!(s1 && s2))
		return (ret);
	ret = ft_strnew((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (ret)
		ft_strcat(ft_strcpy(ret, s1), s2);
	return (ret);
}
