/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:10:11 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/18 20:27:50 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pile_is_sorted(t_pile *pile)
{
	int	value;

	value = pile->value;
	while (pile)
	{
		if (pile->value < value)
			return (-1);
		value = pile->value;
		pile = pile->next;
	}
	return (1);
}

void	pile_put_on_top(t_pile	**pile, int pos)
{
	int	i;

	i = 0;
	if (pos == 1)
		return ;
	if (pos == 2)
	{
		sa(pile);
		return ;
	}
	else
	{
		while (i++ < (pile_get_size(*pile) - (pos - 1)))
			rra(pile);
		i = 0;
		while (i++ < (pile_get_size(*pile) - pos))
		{
			sa(pile);
			ra(pile);
		}
	}
}

void	pile_sort_3(t_pile **pile)
{
	int	biggest_nb_index;

	biggest_nb_index = pile_get_biggest(*pile, 3);
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
	if (pile_is_sorted(*pile_a) == 1)
		return ;
	while (i++ < 2)
	{
		pile_put_on_top(pile_a, (pile_get_smallest(*pile_a, pile_get_size(*pile_a)) + 1));
		pb(pile_a, pile_b);
	}
	pile_sort_3(pile_a);
	pa(pile_a, pile_b);
	pa(pile_a, pile_b);
}
