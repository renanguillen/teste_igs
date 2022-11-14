/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:13:04 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/09/22 00:22:26 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*aux;

	aux = (char *)s;
	while (n > 0)
	{
		aux[n - 1] = c;
		n--;
	}
	return (s);
}
