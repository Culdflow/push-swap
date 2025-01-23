/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robot <robot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 04:28:08 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/23 23:04:02 by robot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	test(t_pile **a, t_pile **b)
{
	print_pile(*a, "PILE A");
	print_pile(*b, "PILE B");
	ft_printf("\n-------------\n");
	sa(a);
	sb(b);
	print_pile(*a, "PILE A");
	print_pile(*b, "PILE B");
	ft_printf("\n-------------\n");
	ss(a, b);
	print_pile(*a, "PILE A");
	print_pile(*b, "PILE B");
	ft_printf("\n-------------\n");
	pb(a, b);
	pa(a, b);
	print_pile(*a, "PILE A");
	print_pile(*b, "PILE B");
	ft_printf("\n-------------\n");
	ra(a);
	rb(b);
	print_pile(*a, "PILE A");
	print_pile(*b, "PILE B");
	ft_printf("\n-------------\n");
	rr(a, b);
	print_pile(*a, "PILE A");
	print_pile(*b, "PILE B");
	ft_printf("\n-------------\n");
	rra(a);
	rrb(b);
	print_pile(*a, "PILE A");
	print_pile(*b, "PILE B");
	ft_printf("\n-------------\n");
	rrr(a, b);
	print_pile(*a, "PILE A");
	print_pile(*b, "PILE B");
	ft_printf("\n-------------\n");
}

int main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2)
		a = parse_str(argv[1]);
	else
		a = parse_opt(argv);
	pile_set_index(a);
	print_pile(a, "PILE A");
	print_pile(b, "PILE B");
	// ft_printf("smallest nb index = %d\n", pile_get_smallest(a, pile_get_size(a)));
	pile_sort_5(&a, &b);
	print_pile(a, "PILE A");
	print_pile(b, "PILE B");
	free_pile(a);
	free_pile(b);
}
