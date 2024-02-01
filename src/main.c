/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:00:15 by rigarrid          #+#    #+#             */
/*   Updated: 2024/02/01 16:06:46 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_stacks	*ft_initlist(int content)
{
	t_stacks	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = NULL;
	return (node);
}

t_stacks	*ft_putfirst(int content, t_stacks *head)
{
	t_stacks	*node;

	node = (t_stacks *)malloc(sizeof(t_stacks));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = head;
	return (node);
}
int ft_onlynbr(char *str)
{
    int	c;

    c = 0;
	while (str[c])
	{
		if ((str[c] >= 48 && str[c] <= 57) || (str[c] == 45 || str[c] == 43))
			c++;
		else
			return (1);
	}
	return (0);
}
int	ft_error(int e)
{
	if (e == 1)
		ft_printf("Only numbers are allowed\n");
	else if (e == 2)
		ft_printf("Found duplicate numbers\n");
	return (1);
}

int ft_countNode(t_stacks *head) 
{ 
    int count;

	count = 0;
    while (head != NULL) { 
        t_stacks *ptr = head->next; 
        while (ptr != NULL) 
		{ 
            if (head->nbr == ptr->nbr) 
			{ 
                count++; 
                break; 
            } 
            ptr = ptr->next; 
        } 
        head = head->next; 
    } 
    return count; 
}

int	main(int argc, char **argv)
{
    t_stacks	*trial;
    int			c = argc - 1;

   if  (ft_onlynbr(argv[c]) == 0)
        	trial = ft_initlist(ft_atoi(argv[c--]));
    while (c >= 1)
    {
        if  (ft_onlynbr(argv[c]) == 0)
        	trial = ft_putfirst(ft_atoi(argv[c--]), trial);
		else
		{
			free(trial);
			return(ft_error(1));
		}
    }
	if (ft_countNode(trial) >= 1)
		return (ft_error(2));
    while (trial->next != NULL)
    {
        ft_printf("%i\n", trial->nbr);
        trial = trial->next;
    }
	ft_printf("%i\n", trial->nbr);
	free(trial);
	return (0);
}
