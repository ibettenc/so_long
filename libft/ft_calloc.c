/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:50:12 by ibettenc          #+#    #+#             */
/*   Updated: 2025/04/20 20:46:57 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	array = (void *)malloc(count * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (count * size));
	return (array);
}
