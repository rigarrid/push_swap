/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:17:07 by rigarrid          #+#    #+#             */
/*   Updated: 2024/01/31 15:01:38 by rigarrid         ###   ########.fr       */
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

#endif