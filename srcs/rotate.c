/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:28 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/07 15:32:58 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_r(t_list **stack, char stk)
{
	t_list	*tmp;

	if (stk == 'a')
		write(1, "ra\n", 3);
	else if (stk == 'b')
		write(1, "rb\n", 3);
	if (!stack || !(*stack))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
	tmp->next = NULL;
}

void	_r_all(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	write(1, "rr\n", 3);
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_back(stack_a, tmp);
	tmp->next = NULL;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_back(stack_b, tmp);
	tmp->next = NULL;
}

void	_rr(t_list **stack, char stk)
{
	t_list	*tmp;

	if (stk == 'a')
		write(1, "rra\n", 4);
	else if (stk == 'b')
		write(1, "rrb\n", 4);
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(stack, tmp->next);
	tmp->next = NULL;
}

void	_rr_all(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	write(1, "rrr\n", 4);
	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(stack_a, tmp->next);
	tmp->next = NULL;
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(stack_b, tmp->next);
	tmp->next = NULL;
}
