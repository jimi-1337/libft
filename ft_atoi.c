/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoujane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 23:28:40 by amoujane          #+#    #+#             */
/*   Updated: 2019/10/25 23:30:18 by amoujane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_signe(const char *s)
{
	int sig;

	sig = 1;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sig = -1;
	}
	return (sig);
}

int			ft_atoi(const char *s)
{
	int				signe;
	long			result;
	long			val;

	result = 0;
	val = 0;
	while ((*s == ' ' || *s == '\t' || *s == '\r' || *s == '\v'
				|| *s == '\f' || *s == '\n') && *s)
		s++;
	signe = ft_signe(s);
	if (*s == '-' || *s == '+')
		s++;
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		val = result;
		result = (result * 10) + ((*s - '0') * (signe));
		if (signe == 1 && result < val)
			return (-1);
		if (signe == -1 && result > val)
			return (0);
		s++;
	}
	return (result);
}
