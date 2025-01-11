/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:10:11 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/11 04:31:48 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (!b || !*b)
		return ;
	tmp = (*b)->next;
	pile_add_front(a, *b);
	*b = tmp;
	ft_printf("pa\n");
}

void	pb(t_pile **b, t_pile **a)
{
	t_pile	*tmp;

	if (!b || !*b)
		return ;
	tmp = (*b)->next;
	pile_add_front(a, *b);
	*b = tmp;
	ft_printf("pb\n");
}