/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:00:55 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/07 15:33:10 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_sa(t_list **stack_a)
{
	t_list	*tmp;

	write(1, "sa\n", 3);
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->next->next;
	ft_lstadd_front(stack_a, (*stack_a)->next);
	(*stack_a)->next->next = tmp;
}

void	_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	write(1, "pa\n", 3);
	if (!stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, tmp);
}

void	_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	write(1, "pb\n", 3);
	if (!stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, tmp);
}
