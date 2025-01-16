/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:10:11 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/16 22:30:14 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	pile_push(t_pile **a, t_pile **b)
{
	if (!b || !*b)
		return (-1);
	pile_add_front(a, b);
	return (0);
}

void	pa(t_pile **a, t_pile **b)
{
	if (pile_push(a, b) == 0)
		ft_printf("pa\n");
}

void	pb(t_pile **b, t_pile **a)
{
	if (pile_push(a, b) == 0)
		ft_printf("pb\n");
}