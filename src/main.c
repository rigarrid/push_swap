/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:00:15 by rigarrid          #+#    #+#             */
/*   Updated: 2024/02/21 15:58:20 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

/*	Asigna los numeros de la lista al array pasado como argumento.	*/

void ft_asing(int *n, t_stacks *head)
{
	n[0] = head->nbr;
	head = head->next;
	n[1] = head->nbr;
	head = head->next;
	n[2] = head->nbr;
	head = head->next;
}

/*	Ordena listas de dos numeros creando una matriz con ellos y
	y comparandolos	*/

void	ft_two(t_stacks *a)
{
	int	copy[2];

	copy[0] = a->nbr;
	a = a->next;
	copy[1] = a->nbr;
	if (copy[0] > copy[1])
		ft_sa(a);
}

/*	Guarda los numeros de la lista en un array y los compara para
	hacer los movimientos adecuados dependiendo del orden.	*/

void	ft_three(t_stacks *head, int argc)
{
	int n[3];

	ft_asing(n, head);
	if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
	{
		ft_sa(head);
		ft_ra(head, argc);
	}
	else if (n[0] > n[1] && n[0] < n[2])
		ft_sa(head);
	else if (n[0] < n[1] && n[0] > n[2])
	{
		ft_ra(head, argc);
		ft_ra(head, argc);
	}
	else if (n[0] > n[1] && n[1] > n[2])
	{
		ft_ra(head, argc);
		ft_sa(head);
	}
	else if (n[0] > n[1] && n[0] > n[2])
		ft_ra(head, argc);

}

/*	Comprueba que la string pasada como argumento solo contenga valores
	numericos.	*/

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

/*	Según el integro pasado como argumento, muestra un mensaje de error 
	en pantalla.  */

int	ft_error(int e)
{
	if (e == 1)
		ft_printf("Only numbers are allowed\n");
	else if (e == 2)
		ft_printf("Found duplicate numbers\n");
	return (1);
}

/*	Crea una copia de la lista pasada como argumento y comprueba que si
	hay números duplicados.	*/

int ft_countNode(t_stacks *head) 
{ 
    int count;
	t_stacks *ptr;

	count = 0;
    while (head != NULL) { 
        ptr = head->next; 
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
    t_stacks	*a;
	t_stacks	*b;
    int			c = argc - 1;

	b = NULL;
	if  (ft_onlynbr(argv[c]) == 0)
		a = ft_initlist(ft_atoi(argv[c--]));
    while (c >= 1)
    {
        if  (ft_onlynbr(argv[c]) == 0)
        	a = ft_putfirst(ft_atoi(argv[c--]), a);
		else
		{
			free(a);
			return(ft_error(1));
		}
    }
	if (ft_countNode(a) >= 1)
		return (ft_error(2));
	ft_makecircle(a);
	if (argc == 3)
		ft_two(a);
	else if (argc == 4)
		ft_three(a, argc);
	}
