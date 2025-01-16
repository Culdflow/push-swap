/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:55:09 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/16 21:25:33 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	pile_rotate(t_pile **pile)
{
	t_pile	*last;

	if (pile_get_size(*pile) < 2)
		return ;	
	last = *pile;
	pile_add_back(pile, *pile);
	*pile = (*pile)->next;
	last->next = NULL;
}

void	ra(t_pile **a)
{
	pile_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_pile **b)
{
	pile_rotate(b);
	ft_printf("rb\n");
}

void	rr(t_pile **a, t_pile **b)
{
	pile_rotate(a);
	pile_rotate(b);
	ft_printf("rr\n");
}
