/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:18:42 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 17:29:00 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*pile_get_smallest(t_pile *start, int nb)
{
	t_pile	*smallest_pile;
	int		index;

	index = 0;
	smallest_pile = start;
	while (start && index < nb)
	{
		if (start->value < smallest_pile->value)
			smallest_pile = start;
		index++;
		start = start->next;
	}
	return (smallest_pile);
}

int	pile_get_med(t_pile *pile)
{
	int	value;
	int	nb;

	value = 0;
	nb = 0;
	while (pile)
	{
		value += pile->value;
		nb++;
		pile = pile->next;
	}
	return (value / nb);
}

t_pile	*get_target_node(t_pile *pile, int nb)
{
	t_pile	*result;
	t_pile	*pile_backup;
	int		diff;

	result = NULL;
	pile_backup = pile;
	diff = 100000;
	while (pile)
	{
		if (nb > pile->value && (nb - pile->value) < diff)
		{
			result = pile;
			diff = nb - pile->value;
		}
		pile = pile->next;
	}
	if (!result)
		result = pile_get_biggest(pile_backup, pile_get_size(pile_backup));
	return (result);
}

t_pile	*get_target_node_b(t_pile *pile, int nb)
{
	t_pile	*result;
	t_pile	*pile_backup;
	int		diff;

	result = NULL;
	pile_backup = pile;
	diff = 100000;
	while (pile)
	{
		if (nb < pile->value && (pile->value - nb) < diff)
		{
			result = pile;
			diff = pile->value - nb;
		}
		pile = pile->next;
	}
	if (!result)
		result = pile_get_smallest(pile_backup, pile_get_size(pile_backup));
	return (result);
}

void	pile_set_index(t_pile *pile)
{
	int	index;

	index = 0;
	while (pile)
	{
		pile->index = index;
		index++;
		pile = pile->next;
	}
}
