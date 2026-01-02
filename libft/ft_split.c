/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsagir <alsagir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 13:50:20 by alsagir           #+#    #+#             */
/*   Updated: 2025/06/20 12:18:39 by alsagir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_word_count(const char *str, char sep)
{
	int	toggle;
	int	count;

	toggle = 0;
	count = 0;
	while (*str)
	{
		if (*str != sep && toggle == 0)
		{
			toggle = 1;
			count++;
		}
		else if (*str == sep)
			toggle = 0;
		str++;
	}
	return (count);
}

static char	*ft_get_word(const char *str, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, str, i);
	word[i] = '\0';
	return (word);
}

static void	*ft_free_all(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	**start;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	start = arr;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			*arr = ft_get_word(s, c);
			if (!*arr)
				return (ft_free_all(start));
			arr++;
		}
		while (*s && *s != c)
			s++;
	}
	*arr = NULL;
	return (start);
}
