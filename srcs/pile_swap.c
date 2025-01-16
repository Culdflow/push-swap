/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:01:04 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/16 21:44:53 by dfeve            ###   ########.fr       */
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
}

void	sa(t_pile **pile)
{
	pile_swap(pile);
	ft_printf("sa\n");
}

void	sb(t_pile **pile)
{
	pile_swap(pile);
	ft_printf("sb\n");
}

void	ss(t_pile **a, t_pile **b)
{
	pile_swap(a);
	pile_swap(b);
	ft_printf("ss\n");
}