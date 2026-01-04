/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsagir <alsagir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:33:44 by alsagir           #+#    #+#             */
/*   Updated: 2025/06/24 20:28:16 by alsagir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ds;
	const unsigned char	*sr;

	if (!dst && !src)
		return (NULL);
	ds = (unsigned char *)dst;
	sr = (const unsigned char *)src;
	if (ds < sr)
		while (len--)
			*ds++ = *sr++;
	else
		while (len --)
			ds[len] = sr[len];
	return (dst);
}
