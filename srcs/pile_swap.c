/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:01:04 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 17:21:09 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	pile_swap(t_pile **pile)
{
	t_pile	*tmp;

	if (pile_get_size(*pile) < 2)
		return ;
	tmp = *pile;
	*pile = (*pile)->next;
	if ((*pile)->next)
		tmp->next = (*pile)->next;
	else
		tmp->next = NULL;
	(*pile)->next = tmp;
	pile_set_index(*pile);
}

void	sa(t_pile **pile)
{
	if ((*pile)->pile_label == 'B')
		sb(pile);
	else
	{
		pile_swap(pile);
		ft_printf("sa\n");
	}
}

void	sb(t_pile **pile)
{
	if ((*pile)->pile_label == 'A')
		sa(pile);
	else
	{
		pile_swap(pile);
		ft_printf("sb\n");
	}
}

void	ss(t_pile **a, t_pile **b)
{
	pile_swap(a);
	pile_swap(b);
	ft_printf("ss\n");
}
