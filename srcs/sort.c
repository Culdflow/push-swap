/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:10:11 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 16:36:12 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pile_is_sorted(t_pile *pile, char type)
{
	int	value;

	if (type == 'B')
	{
		value = pile->value;
		while (pile)
		{
			if (pile->value > value)
				return (-1);
			value = pile->value;
			pile = pile->next;
		}
	}
	else
	{
		value = pile->value;
		while (pile)
		{
			if (pile->value < value)
				return (-1);
			value = pile->value;
			pile = pile->next;
		}
	}
	return (1);
}

void	pile_put_on_top(t_pile **pile, int pos)
{
	int	i;

	i = 0;
	if (pos == 0)
		return ;
	else
	{
		if ((pile_get_size(*pile) / 2) <= pos)
		{
			while (i++ < (pile_get_size(*pile) - pos))
				rra(pile);
		}
		else
		{
			while (i++ < pos)
				ra(pile);
		}
	}
}

int	pile_put_on_top_calculate(t_pile *pile, int pos)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (pos == 0)
		return (0);
	else
	{
		if ((pile_get_size(pile) / 2) <= pos)
		{
			while (i++ < (pile_get_size(pile) - pos))
				result++;
		}
		else
		{
			while (i++ < pos)
				result++;
		}
	}
	return (result);
}

void	pile_sort_3(t_pile **pile)
{
	int	biggest_nb_index;

	biggest_nb_index = pile_get_biggest(*pile, 3)->index;
	if (biggest_nb_index == 0)
		ra(pile);
	else if (biggest_nb_index == 1)
		rra(pile);
	if ((*pile)->value > (*pile)->next->value)
		sa(pile);
}

void	pile_sort_5(t_pile **pile_a, t_pile **pile_b)
{
	int	i;

	i = 0;
	if (pile_is_sorted(*pile_a, 'S') == 1)
		return ;
	while (i++ < 2)
	{
		pile_put_on_top(pile_a, (pile_get_smallest(*pile_a, pile_get_size(*pile_a)))->index);
		pb(pile_a, pile_b);
	}
	pile_sort_3(pile_a);
	pa(pile_a, pile_b);
	pa(pile_a, pile_b);
}

void	pile_push_to_target_node(t_pile *node, t_pile **node_pile, t_pile **target_node_pile)
{
	if (node->pile_label == 'A')
		node->target_node = get_target_node(*target_node_pile, node->value);
	else
		node->target_node = get_target_node_b(*target_node_pile, node->value);
	if (node->target_node)
		pile_put_on_top(target_node_pile, node->target_node->index);
	pile_put_on_top(node_pile, node->index);
	if (node->pile_label == 'A')
		pb(node_pile, target_node_pile);
	else
		pa(target_node_pile, node_pile);
}

int	pile_push_to_target_node_calculate(t_pile *node, t_pile *node_pile, t_pile *target_node_pile)
{
	int	result;

	result = 0;
	if (node->pile_label == 'A')
		node->target_node = get_target_node(target_node_pile, node->value);
	else
		node->target_node = get_target_node_b(target_node_pile, node->value);
	if (node->target_node && target_node_pile)
		result += pile_put_on_top_calculate(target_node_pile, node->target_node->index);
	result += pile_put_on_top_calculate(node_pile, node->index);
	result++;
	return (result);
}

t_pile	*get_best_move(t_pile *node_pile, t_pile *target_node_pile)
{
	t_pile	*best_move;
	t_pile	*pile;
	int		best_move_cost;
	int		cost;

	pile = node_pile;
	best_move = pile;
	best_move_cost = 100000;
	while (pile)
	{
		cost = pile_push_to_target_node_calculate(pile, node_pile, target_node_pile);
		if (cost == 1)
			return (pile);
		if (cost < best_move_cost)
		{
			best_move = pile;
			best_move_cost = cost;
		}
		pile = pile->next;
	}
	return (best_move);
}
