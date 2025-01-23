/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robot <robot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:10:11 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/23 22:47:08 by robot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	pile_push(t_pile **a, t_pile **b, char label)
{
	if (!b || !*b)
		return (-1);
	pile_add_front(a, b);
	(*a)->pile_label = label;
	pile_set_index(*a);
	pile_set_index(*b);
	return (0);
}

void	pa(t_pile **a, t_pile **b)
{
	if (pile_push(a, b, 'A') == 0)
		ft_printf("pa\n");
}

void	pb(t_pile **a, t_pile **b)
{
	if (pile_push(b, a, 'B') == 0)
		ft_printf("pb\n");
}