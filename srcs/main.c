/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 04:28:08 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/11 00:49:05 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_pile	*a;

	a = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2)
		a = parse_str(argv[1]);
	else
		a = parse_opt(argv);
	print_pile(a); 
}
