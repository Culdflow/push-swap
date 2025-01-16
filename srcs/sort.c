/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:10:11 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/16 23:49:41 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	pile_sort_5(t_pile **pile)
{
	while ((*pile)->value > (*pile)->next->value)
	{
		pile_sort_3(pile);
		pile_sort_3(&(*pile)->next);
		pile_sort_3(&(*pile)->next->next);
	}
}