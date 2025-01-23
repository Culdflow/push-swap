/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robot <robot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 05:15:53 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/23 22:30:16 by robot            ###   ########.fr       */
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
		ft_printf("%d	%d	\033[0;32m[%c]\033[0m\n\n", start->value, start->index, start->pile_label);
		start = start->next;
	}
}

int	check_pile(int nb, t_pile *start)
{
	while (start)
	{
		if (start->value == nb)
			return (-1);
		start = start->next;
	}
	return (1);
}

int	pile_get_size(t_pile *start)
{
	int	result;

	result = 0;
	while(start)
	{
		result++;
		start = start->next;
	}
	return (result);
}

t_pile	*pile_get_pos(int nb, t_pile *start)
{
	int	pile_nb;

	pile_nb = 0;
	if (nb < 0)
		return (NULL);
	while (start)
	{
		if (pile_nb == nb)
			return (start);
		start = start->next;
		pile_nb++;
	}
	return (NULL);
}

void	free_pile(t_pile *start)
{
	t_pile	*tmp;

	if (!start)
		return ;
	while (start->next)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
	free(start);
}

int	pile_get_biggest(t_pile *start, int nb)
{
	int	biggest_value;
	int	index;
	int	biggest_index;
	
	biggest_index = 0;
	index = 0;
	while (start && index < nb)
	{
		if (index == 0)
			biggest_value = start->value;
		else if (start->value > biggest_value)
		{
			biggest_index = index;
			biggest_value = start->value;
		}
		index++;
		start = start->next;
	}
	return (biggest_index);
}

int	pile_get_smallest(t_pile *start, int nb)
{
	int	smallest_value;
	int	index;
	int	smallest_index;
	
	smallest_index = 0;
	index = 0;
	while (start && index < nb)
	{
		if (index == 0)
			smallest_value = start->value;
		else if (start->value < smallest_value)
		{
			smallest_index = index;
			smallest_value = start->value;
		}
		index++;
		start = start->next;
	}
	return (smallest_index);
}

int	pile_get_med(t_pile *pile)
{
	int	value;
	int	nb;

	value = 0;
	nb = 0;
	while (pile)
	{
		value += pile->value;
		nb++;
		pile = pile->next;
	}
	return (value / nb);
}

t_pile	*get_target_node(t_pile *pile, int nb)
{
	t_pile	*result;
	int		diff;

	result = NULL;
	diff = 100000;
	while(pile)
	{
		if(nb > pile->value && (nb - pile->value) < diff)
		{
			result = pile;
			diff = nb - pile->value;
		}
		pile = pile->next;
	}
	return (result);
}

void	pile_set_index(t_pile *pile)
{
	int	index;

	index = 0;           
	while (pile)
	{
		pile->index = index;
		index++;
		pile = pile->next;
	}
}