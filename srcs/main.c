/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 04:28:08 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/27 17:15:08 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
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
	algorithme(&a, &b);
	free_pile(a);
	free_pile(b);
}
