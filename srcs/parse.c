/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:23:02 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/11 02:41:03 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (-1);
		i++;
	}
	return (1);
}

t_pile	*parse_str(char *str)
{
	char	**split;
	t_pile	*result;
	int		i;

	split = ft_split(str, ' ');
	result = malloc(sizeof(t_pile));
	result->next = NULL;
	i = 0;
	while (split[i])
	{
		if ((split[i][0] == '-' || split[i][0] == '+') && !split[i][1])
			error("Need a number as argument", result);
		if (check_pile(ft_atoi(split[i]), result) == -1)
			error("numbers have to be different from one another", result);
		if (ft_atoi(split[i]) > INT_MAX || ft_atoi(split[i]) < INT_MIN)
			error("Number not in range", result);
		if (i == 0)
			result->value = ft_atoi(split[i]);
		else
			pile_add_back(result, new_pile(ft_atoi(split[i])));
		i++;
	}
	return (result);
}

t_pile	*parse_opt(char **opt)
{
	t_pile	*result;
	int		i;

	i = 1;
	result = malloc(sizeof(t_pile));
	result->next = NULL;
	while (opt[i])
	{
		// ft_printf("el = %s\n", opt[i]);
		// ft_printf("to nb = %d\n", ft_atoi(opt[i]));
		if (((opt[i][0] == '-' || opt[i][0] == '+')&& !opt[i][1]) || check_num(opt[i]) == -1)
			error("Need a number as argument", result);
		if (check_pile(ft_atoi(opt[i]), result) == -1)
			error("numbers have to be different from one another", result);
		if (ft_atoi(opt[i]) > INT_MAX || ft_atoi(opt[i]) < INT_MIN)
			error("Number not in range", result);
		if (i == 1)
			result->value = ft_atoi(opt[i]);
		else
			pile_add_back(result, new_pile(ft_atoi(opt[i])));
		i++;
	}
	return (result);
}
