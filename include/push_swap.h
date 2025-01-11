/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 04:34:06 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/11 04:24:47 by dfeve            ###   ########.fr       */
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
void	print_pile(t_pile *start);
void	free_pile(t_pile *start);
void	pile_add_back(t_pile *start, t_pile *pile);
void	pile_add_front(t_pile *start, t_pile *pile);
t_pile	*pile_get_last(t_pile *start);
t_pile	*new_pile(int value);


//-----------------------PARSE------------------------

t_pile	*parse_str(char *str);
t_pile	*parse_opt(char **opt);

//-----------------------ERROR------------------------

void	error(char *str, t_pile *pile);

#endif