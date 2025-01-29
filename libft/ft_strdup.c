/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:44:57 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2025/01/29 16:06:18 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size_len;

	size_len = ft_strlen(s1);
	ptr = (char *)malloc(size_len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size_len);
	ptr[size_len] = '\0';
	return (ptr);
}
