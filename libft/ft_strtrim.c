/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:00:23 by ibettenc          #+#    #+#             */
/*   Updated: 2025/04/26 17:06:51 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	int		len;
	char	*dst;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (is_set(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && is_set(s1[end - 1], set))
		end--;
	len = end - start;
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	while (start < end)
		dst[i++] = s1[start++];
	dst[i] = '\0';
	return (dst);
}
