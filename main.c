/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 04:28:08 by dfeve             #+#    #+#             */
/*   Updated: 2024/12/30 23:02:04 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile  *new_pile(int value)
{
    t_pile  *result;

    result = malloc(sizeof(t_pile));
    result->next = NULL;
    result->value = value;
    return (result);
}

t_pile  *pile_get_last(t_pile *start)
{
    if (!start)
        return (NULL);
    if (!start->next)
        return (start);
    return (pile_get_last(start->next));
}

void    pile_add_back(t_pile *start, t_pile *pile)
{
    t_pile  *last;

    last = pile_get_last(start);
    last->next = pile;
}

void    print_pile(t_pile *start)
{
    if (!start)
        return ;
    ft_printf("%d\n", start->value);
    if (start->next)
        print_pile(start->next);
}

t_pile  *parse_str(char *str)
{
    char    **split;
    t_pile  *result;
    int     i;

    split = ft_split(str, ' ');
    result = malloc(sizeof(t_pile));
    result->next = NULL;
    i = 0;
    while (split[i])
    {
        if (i == 0)
            result->value = ft_atoi(split[i]);
        else
            pile_add_back(result, new_pile(ft_atoi(split[i])));
        i++;
    }
    return (result);
}

int main(int argc, char **argv)
{
    t_pile  *a;

    a = NULL;
    if (argc <= 1)
        return (0);
    if (argc == 2)
       a = parse_str(argv[1]);
    print_pile(a); 
}
