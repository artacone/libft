/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvertie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 09:23:46 by rvertie           #+#    #+#             */
/*   Updated: 2021/04/14 10:31:34 by rvertie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static unsigned int	ncheck(int n, char *digits, int *i)
{
	unsigned int	un;

	digits[0] = 0;
	if (n < 0)
	{
		digits[0] = '-';
		un = -n;
		return (un);
	}
	un = n;
	if (un == 0)
	{
		digits[1] = '0';
		*i = 2;
	}
	return (un);
}

char	*ft_itoa(int n)
{
	char			digits[11];
	int				i;
	char			*res;
	unsigned int	un;

	i = 1;
	un = ncheck(n, digits, &i);
	while (un)
	{
		digits[i++] = un % 10 + '0';
		un /= 10;
	}
	res = (char *)malloc(i + 1);
	if (res == NULL)
		return (NULL);
	if (digits[0] == '-')
		res[un++] = '-';
	while (i > 1)
		res[un++] = digits[--i];
	res[un] = '\0';
	return (res);
}
