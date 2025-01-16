/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:02:22 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/16 21:27:09 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	pile_reverse_rotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*og_last;
	int		pile_size;

	og_last = pile_get_last(*pile);
	pile_size = pile_get_size(*pile);
	if (pile_get_size(*pile) <= 1)
		return ;
	if ((pile_size - 2) >= 0)
		last = pile_get_nb(pile_size - 2, *pile);
	else
		last = *pile;
	og_last->next = *pile;
	*pile = og_last;
	last->next = NULL;
}

void	rra(t_pile	**a)
{
	pile_reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_pile	**b)
{
	pile_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_pile	**a, t_pile **b)
{
	pile_reverse_rotate(a);
	pile_reverse_rotate(b);
	ft_printf("rrr\n");
}