/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:54:39 by rigarrid          #+#    #+#             */
/*   Updated: 2024/02/21 15:10:45 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*	Guarda el nodo principal del stack en una copia y
	lo asigna como el siguiente nodo del ultimo, haciendo
	asi una lista circular	*/

t_stacks	*ft_makecircle(t_stacks *head)
{
	t_stacks	*node;

	node = head;
	while (head->next != NULL)
		head = head->next;
	head->next = node;
	head = head->next;
	return (head);
}

/*	Reserva espacio en la memoria para el primer nodo e inicia una lista
	 con el contenido otorgado.	*/

t_stacks	*ft_initlist(int content)
{
	t_stacks	*node;

	node = (t_stacks *)malloc(sizeof(t_stacks *));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = NULL;
	return (node);
}

/*	Reserva espacio en la memoria para un nuevo nodo, asigna el contenido
	y lo convierte en el primer nodo de la lista pasada como argumento.	*/

t_stacks	*ft_putfirst(int content, t_stacks *head)
{
	t_stacks	*node;

	node = (t_stacks *)malloc(sizeof(t_stacks *));
	if (!node)
		return (NULL);
	node->nbr = content;
	node->next = head;
	return (node);
}