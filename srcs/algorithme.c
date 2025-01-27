/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:24:15 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 17:25:15 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_a_to_b(t_pile **pile_a, t_pile **pile_b)
{
	int	i;

	i = 0;
	while (i++ < 2 && pile_get_size(*pile_a) > 3)
		pb(pile_a, pile_b);
	while (pile_get_size(*pile_a) > 3)
		pile_push_to_target_node(get_best_move(*pile_a, *pile_b),
			pile_a, pile_b);
}

static void	push_b_to_a(t_pile **pile_a, t_pile **pile_b)
{
	while (pile_b && *pile_b)
		pile_push_to_target_node(get_best_move(*pile_b,
				*pile_a), pile_b, pile_a);
}

void	algorithme(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*smallest;

	smallest = NULL;
	push_a_to_b(pile_a, pile_b);
	pile_sort_3(pile_a);
	push_b_to_a(pile_a, pile_b);
	pile_put_on_top(pile_a, pile_get_smallest(*pile_a,
			pile_get_size(*pile_a))->index);
}
