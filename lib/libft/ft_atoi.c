/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:40:52 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 17:31:57 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\r'
		|| c == '\t' || c == '\n'
		|| c == '\v')
		return (1);
	return (-1);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(nptr[i]) == 1)
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			if (!nptr[i + 1])
				return (2147483648);
			sign *= -1;
		}
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
int main()
{
	printf("%d", ft_atoi("123"));
}*/
