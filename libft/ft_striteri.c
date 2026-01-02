/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsagir <alsagir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:40:48 by alsagir           #+#    #+#             */
/*   Updated: 2025/06/25 03:08:52 by alsagir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	idx;

	if (s == NULL || f == NULL)
		return ;
	idx = 0;
	while (*(s + idx))
	{
		f(idx, s + idx);
		idx++;
	}
}
