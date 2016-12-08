/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 01:28:49 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/05 14:35:27 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (*big && little[i] == '\0')
		return ((char *)(big));
	if (n < ft_strlen(little))
		return (NULL);
	while (big[i])
	{
		j = 0;
		while ((i + j) < n && big[i + j] && little[j]
		&& big[i + j] == little[j])
			j++;
		if (little[j] == '\0' || j == n)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
