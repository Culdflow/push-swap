/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:10:11 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 17:23:39 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pile_is_sorted(t_pile *pile, char type)
{
	int	value;

	if (type == 'B')
	{
		value = pile->value;
		while (pile)
		{
			if (pile->value > value)
				return (-1);
			value = pile->value;
			pile = pile->next;
		}
	}
	else
	{
		value = pile->value;
		while (pile)
		{
			if (pile->value < value)
				return (-1);
			value = pile->value;
			pile = pile->next;
		}
	}
	return (1);
}

void	pile_put_on_top(t_pile **pile, int pos)
{
	int	i;

	i = 0;
	if (pos == 0)
		return ;
	else
	{
		if ((pile_get_size(*pile) / 2) <= pos)
		{
			while (i++ < (pile_get_size(*pile) - pos))
				rra(pile);
		}
		else
		{
			while (i++ < pos)
				ra(pile);
		}
	}
}

int	pile_put_on_top_calculate(t_pile *pile, int pos)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (pos == 0)
		return (0);
	else
	{
		if ((pile_get_size(pile) / 2) <= pos)
		{
			while (i++ < (pile_get_size(pile) - pos))
				result++;
		}
		else
		{
			while (i++ < pos)
				result++;
		}
	}
	return (result);
}

void	pile_sort_3(t_pile **pile)
{
	int	biggest_nb_index;

	biggest_nb_index = pile_get_biggest(*pile, 3)->index;
	if (biggest_nb_index == 0)
		ra(pile);
	else if (biggest_nb_index == 1)
		rra(pile);
	if ((*pile)->value > (*pile)->next->value)
		sa(pile);
}

void	pile_sort_5(t_pile **pile_a, t_pile **pile_b)
{
	int	i;

	i = 0;
	if (pile_is_sorted(*pile_a, 'S') == 1)
		return ;
	while (i++ < 2)
	{
		pile_put_on_top(pile_a,
			(pile_get_smallest(*pile_a, pile_get_size(*pile_a)))->index);
		pb(pile_a, pile_b);
	}
	pile_sort_3(pile_a);
	pa(pile_a, pile_b);
	pa(pile_a, pile_b);
}
