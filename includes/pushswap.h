/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:17:07 by rigarrid          #+#    #+#             */
/*   Updated: 2024/02/21 13:58:53 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include  "../libft/includes/libft.h"

typedef struct s_stack
{
	int             nbr;
	struct s_stack	*next;
}	t_stacks;

t_stacks	*ft_makecircle(t_stacks *head);
t_stacks	*ft_initlist(int content);
t_stacks	*ft_putfirst(int content, t_stacks *head);
void		ft_sa(t_stacks *head);
void    	ft_ra(t_stacks *head, int counter);

#endif