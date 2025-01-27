/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:15:53 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 17:17:54 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*new_pile(int value)
{
	t_pile	*result;

	result = malloc(sizeof(t_pile));
	result->next = NULL;
	result->target_node = NULL;
	result->value = value;
	result->pile_label = 'A';
	result->index = 0;
	return (result);
}

t_pile	*pile_get_last(t_pile *start)
{
	if (!start)
		return (NULL);
	if (!start->next)
		return (start);
	return (pile_get_last(start->next));
}

void	pile_add_back(t_pile **start, t_pile *pile)
{
	t_pile	*last;

	if (!start)
		return ;
	if (!*start)
	{
		*start = pile;
		return ;
	}
	last = pile_get_last(*start);
	last->next = pile;
}

void	pile_add_front(t_pile **start, t_pile **pile)
{
	t_pile	*tmp;

	if (!start)
		return ;
	if (!*start)
	{
		*start = *pile;
		*pile = (*pile)->next;
		(*start)->next = NULL;
		return ;
	}
	tmp = *start;
	*start = *pile;
	*pile = (*pile)->next;
	(*start)->next = tmp;
}

void	print_pile(t_pile *start, char *str)
{
	ft_printf("\033[0;32m[%s]\033[0m\n", str);
	if (!start)
		return ;
	while (start)
	{
		ft_printf("%d	%d	\033[0;32m[%c]\033[0m\n\n",
			start->value, start->index, start->pile_label);
		start = start->next;
	}
}
