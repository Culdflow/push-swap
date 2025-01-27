/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:17:23 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 17:28:02 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_pile(int nb, t_pile *start)
{
	while (start)
	{
		if (start->value == nb)
			return (-1);
		start = start->next;
	}
	return (1);
}

int	pile_get_size(t_pile *start)
{
	int	result;

	result = 0;
	while (start)
	{
		result++;
		start = start->next;
	}
	return (result);
}

t_pile	*pile_get_pos(int nb, t_pile *start)
{
	int	pile_nb;

	pile_nb = 0;
	if (nb < 0)
		return (NULL);
	while (start)
	{
		if (pile_nb == nb)
			return (start);
		start = start->next;
		pile_nb++;
	}
	return (NULL);
}

void	free_pile(t_pile *start)
{
	t_pile	*tmp;

	if (!start)
		return ;
	while (start->next)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
	free(start);
}

t_pile	*pile_get_biggest(t_pile *start, int nb)
{
	t_pile	*result;
	int		index;

	result = start;
	index = 0;
	while (start && index < nb)
	{
		if (start->value > result->value)
			result = start;
		index++;
		start = start->next;
	}
	return (result);
}
