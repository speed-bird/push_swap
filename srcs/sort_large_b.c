/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:44 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/07 15:56:46 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_double_fill(t_list **stack_a, t_list **stack_b)
{
	t_list	*penult;

	penult = *stack_b;
	while (penult && penult->next && penult->next->next)
		penult = penult->next;
	while (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next
		&& (ft_lstlast(*stack_a)->content == ft_lstlast(*stack_b)->content + 1
			|| ft_lstlast(*stack_a)->content == penult->content - 1))
	{
		_rr_all(stack_a, stack_b);
		_pb(stack_a, stack_b);
	}
	while (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next
		&& ((*stack_a)->next->content == (*stack_b)->next->content + 1
			|| (*stack_a)->next->content == (*stack_b)->content - 1))
	{
		_r_all(stack_a, stack_b);
		_pb(stack_a, stack_b);
	}
}

void	_simple_fill(t_list **stack_a, t_list **stack_b)
{	
	t_list	*penult;

	while (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next
		&& (!_is_ordered(*stack_a) || _min(*stack_a) < _max(*stack_b))
		&& ((*stack_a)->content == (*stack_b)->content + 1
			|| (*stack_a)->content == ft_lstlast(*stack_b)->content - 1))
		_pb(stack_a, stack_b);
	while (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next
		&& (!_is_ordered(*stack_a) || _min(*stack_a) < _max(*stack_b))
		&& (ft_lstlast(*stack_a)->content == ft_lstlast(*stack_b)->content - 1
			|| ft_lstlast(*stack_a)->content == (*stack_b)->content + 1))
	{
		_rr(stack_a, 'a');
		_pb(stack_a, stack_b);
	}
	penult = *stack_b;
	while (penult && penult->next && penult->next->next)
		penult = penult->next;
	while (*stack_a && *stack_b && (*stack_a)->next && (*stack_b)->next
		&& ((*stack_a)->content == ft_lstlast(*stack_b)->content + 1
			|| (*stack_a)->content == penult->content - 1))
	{
		_rr(stack_b, 'b');
		_pb(stack_a, stack_b);
	}
}

void	_next_layer(t_list **stack_o, int *min, int *max, int size)
{
	int	i;
	int	layer;

	if (size <= 200)
		layer = size / 4;
	else
		layer = size / 8;
	if (!layer)
		layer = 1;
	*min = (*stack_o)->content;
	i = 0;
	while (*stack_o && (*stack_o)->next && i++ < layer)
		*stack_o = (*stack_o)->next;
	*max = (*stack_o)->content;
	if (*stack_o && (*stack_o)->next)
		*stack_o = (*stack_o)->next;
}

int	_front_item_index(t_list *stack, int *front_val, int min, int max)
{
	int	front;
	int	size;

	size = ft_lstsize(stack);
	front = 0;
	while (stack && stack->next && front <= size / 2
		&& (stack->content < min || stack->content > max))
	{
		front++;
		stack = stack->next;
	}
	*front_val = stack->content;
	return (front);
}

int	_back_item_index(t_list *stack, int *back_val, int min, int max)
{
	t_list	*tmp;
	int		back;
	int		size;
	int		i;

	size = ft_lstsize(stack);
	back = size - 1;
	tmp = stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	i = 0;
	while (tmp && back >= size / 2
		&& (tmp->content < min || tmp->content > max))
	{
		back--;
		tmp = stack;
		i = back;
		while (tmp && tmp->next && i--)
			tmp = tmp->next;
	}
	*back_val = tmp->content;
	return (back);
}
