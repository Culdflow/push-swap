/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 04:01:04 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/11 04:09:43 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_pile *pile, int print)
{
	t_pile	*tmp;

	tmp = pile;
	pile = pile->next;
	tmp->next = pile->next;
	pile->next = tmp;
	if (print == 1)
		ft_printf("sa\n");
}

void	sb(t_pile *pile, int print)
{
	t_pile	*tmp;

	tmp = pile;
	pile = pile->next;
	tmp->next = pile->next;
	pile->next = tmp;
	if (print == 1)
		ft_printf("sb\n");
}

void	ss(t_pile *a, t_pile *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}