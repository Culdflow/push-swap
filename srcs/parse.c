/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:23:02 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/07 05:24:19 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	result = new_pile(ft_atoi(opt[i++]));
	while (opt[i])
		pile_add_back(result, new_pile(ft_atoi(opt[i++])));
	return (result);
}