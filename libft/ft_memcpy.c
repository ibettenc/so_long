/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:05:16 by ibettenc          #+#    #+#             */
/*   Updated: 2025/04/11 16:22:23 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pifd;
	unsigned char	*pifs;

	if (dest == NULL && src == NULL)
		return (dest);
	pifd = (unsigned char *) dest;
	pifs = (unsigned char *) src;
	while (n > 0)
	{
		*pifd = *pifs;
		pifd++;
		pifs++;
		n--;
	}
	return (dest);
}
