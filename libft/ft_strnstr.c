/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:23:38 by ibettenc          #+#    #+#             */
/*   Updated: 2025/04/26 17:43:09 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!str && len == 0)
		return (NULL);
	if (to_find[0] == 0)
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j]
			&& i + j < len)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main()
{
	const char *str = "\0";
	const char *to_find = "i";
	size_t len = 0;
	printf("%s", ft_strnstr(str, to_find, len));
	return 0;
}*/
