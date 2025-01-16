/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 04:34:06 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/16 23:47:02 by dfeve            ###   ########.fr       */
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

int		check_pile(int nb, t_pile *start);
int		pile_get_size(t_pile *start);
int		pile_get_biggest(t_pile *start, int nb);
void	print_pile(t_pile *start, char *str);
void	free_pile(t_pile *start);
void	pile_add_back(t_pile **start, t_pile *pile);
void	pile_add_front(t_pile **start, t_pile **pile);
t_pile	*pile_get_last(t_pile *start);
t_pile	*new_pile(int value);
t_pile	*pile_get_nb(int nb, t_pile *start);

//---------------------SORT--------------------------

void	pile_sort_3(t_pile **pile);
void	pile_sort_5(t_pile **pile);

//-----------------------PARSE------------------------

t_pile	*parse_str(char *str);
t_pile	*parse_opt(char **opt);

//-----------------------ERROR------------------------

void	error(char *str, t_pile *pile);

//-------------------PILE_COMMANDS--------------------

void	pa(t_pile **a, t_pile **b);
void	pb(t_pile **b, t_pile **a);
void	sa(t_pile **pile);
void	sb(t_pile **pile);
void	ss(t_pile **a, t_pile **b);
void	ra(t_pile **a);
void	rb(t_pile **b);
void	rr(t_pile **a, t_pile **b);
void	rra(t_pile	**a);
void	rrb(t_pile	**b);
void	rrr(t_pile	**a, t_pile **b);

#endif