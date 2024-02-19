/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:34:22 by rigarrid          #+#    #+#             */
/*   Updated: 2024/02/19 16:16:01 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void ft_sa(t_stacks *head)
{
    int number[2];
    t_stacks *copy;

    copy = head->next;
    number[0] = head->nbr;
    number[1] = copy->nbr;
    head->nbr = number[1];
    head = head->next;
    head->nbr = number[0];
    ft_printf("sa\n");
}
void    ft_ra(t_stacks *head, int counter)
{
    int first;
    t_stacks    *copy;

    counter = counter - 2;
    copy = head->next;
    first = head->nbr;
    while (counter != 0)
    {
        head->nbr = copy->nbr;
        head = head->next;
        copy = copy->next;
        counter--;
    }
    head->nbr = first;
    ft_printf("ra\n");
}