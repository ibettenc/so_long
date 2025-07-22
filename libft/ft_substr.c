/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:07:54 by ibettenc          #+#    #+#             */
/*   Updated: 2025/04/21 15:34:55 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
		return (ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = str[start + i];
		i++;
	}
	return (dst);
}
//l:23 same as return("") :alloue 1byte pour len+1 charactere (ici 0+1) pour ""
//l:26 sizeof retourne la taille en octet : int = 4, char = 1
