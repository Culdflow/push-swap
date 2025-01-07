/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 04:34:06 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/07 05:25:04 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_pile
{
    struct s_pile   *next;
    int             value;
}   t_pile;

//-----------------------PILE------------------------

void	check_pile(int nb, t_pile *start);
void	print_pile(t_pile *start);
void	pile_add_back(t_pile *start, t_pile *pile);
t_pile	*pile_get_last(t_pile *start);
t_pile	*new_pile(int value);

//-----------------------PARSE------------------------

t_pile	*parse_str(char *str);
t_pile	*parse_opt(char **opt);

#endif