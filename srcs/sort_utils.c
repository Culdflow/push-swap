/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:23:06 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 17:29:17 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pile_push_to_target_node(t_pile *node,
	t_pile **node_pile, t_pile **target_node_pile)
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

int	pile_push_to_target_node_calculate(t_pile *node,
		t_pile *node_pile, t_pile *target_node_pile)
{
	int	result;

	result = 0;
	if (node->pile_label == 'A')
		node->target_node = get_target_node(target_node_pile, node->value);
	else
		node->target_node = get_target_node_b(target_node_pile, node->value);
	if (node->target_node && target_node_pile)
		result += pile_put_on_top_calculate(target_node_pile,
				node->target_node->index);
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
		cost = pile_push_to_target_node_calculate(pile,
				node_pile, target_node_pile);
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
