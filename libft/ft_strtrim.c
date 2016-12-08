/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 01:43:14 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/05 14:35:09 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	ret = NULL;
	if (!(s))
		return (ret);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[j])
		j++;
	j--;
	while (j >= 0 && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	ret = ft_strnew((j - i + 1 < 0) ? 1 : j - i + 1);
	if (ret)
		ret = ft_strncpy(ret, &(s[i]), (j - i + 1 < 0) ? 1 : j - i + 1);
	return (ret);
}
