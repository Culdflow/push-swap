/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:15:53 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/11 00:20:22 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*new_pile(int value)
{
	t_pile	*result;

	result = malloc(sizeof(t_pile));
	result->next = NULL;
	result->value = value;
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

void	pile_add_back(t_pile *start, t_pile *pile)
{
	t_pile	*last;

	last = pile_get_last(start);
	last->next = pile;
}

void	print_pile(t_pile *start)
{
	if (!start)
		return ;
	ft_printf("%d\n", start->value);
	if (start->next)
		print_pile(start->next);
}

int	check_pile(int nb, t_pile *start)
{
	t_pile	*st;

	st = start;
	while (start)
	{
		if (start->value == nb)
			return (-1);
		start = start->next;
	}
	return (1);
}

void	free_pile(t_pile *start)
{
	t_pile	*tmp;

	while (start->next)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
	free(start);
}