/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:15:29 by aditsch           #+#    #+#             */
/*   Updated: 2016/11/10 17:38:24 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcdup(const char *s, char c)
{
	char	*s_dup;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	s_dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!s_dup)
		return (NULL);
	s_dup[i] = '\0';
	i--;
	while (i >= 0)
	{
		s_dup[i] = s[i];
		i--;
	}
	return (s_dup);
}

static int		ft_count_words(char const *str, int c)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static int		ft_len_words(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**char_tab;

	i = 0;
	j = 0;
	char_tab = NULL;
	if (!s)
		return (NULL);
	char_tab = (char**)malloc(sizeof(char *)
	* ft_count_words(s, c) + ft_len_words(s, c) + 1);
	if (!char_tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			char_tab[j] = ft_strcdup((s + i), c);
			j++;
		}
		i++;
	}
	char_tab[j] = NULL;
	return (char_tab);
}
