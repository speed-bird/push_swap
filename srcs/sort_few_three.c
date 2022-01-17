/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:34 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/08 10:30:31 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_sort_three(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
	{
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
			_sa(stack_a);
		else if ((*stack_a)->content < (*stack_a)->next->next->content)
			_sa(stack_a);
	}
	else if ((*stack_a)->next->content > (*stack_a)->next->next->content)
		if ((*stack_a)->content < (*stack_a)->next->next->content)
			_sa(stack_a);
}

int	_front_end_few(t_list *stack)
{
	int		front;
	int		size;
	t_list	*tmp;

	tmp = stack;
	size = ft_lstsize(stack);
	front = 1;
	while (tmp && tmp->next && front <= size / 2
		&& ((tmp->next->content != ft_lstlast(stack)->content
				&& (tmp->content < tmp->next->content
					|| (tmp->content == _max(stack)
						&& tmp->next->content == _min(stack))))
			|| (tmp->next->content == ft_lstlast(stack)->content
				&& tmp->next->content < stack->content)))
	{
		front++;
		tmp = tmp->next;
	}
	return (front);
}

int	_back_end_few(t_list *stack)
{
	t_list	*tmp;
	int		back;
	int		min;
	int		size;
	int		i;

	size = ft_lstsize(stack);
	back = size - 1;
	min = _min(stack);
	tmp = stack;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	if (tmp->next->content > stack->content && stack->content != _min(stack))
		return (back);
	i = 0;
	while (tmp && back > size / 2
		&& (tmp->content < tmp->next->content || tmp->next->content == min))
	{
		back--;
		tmp = stack;
		i = back - 1;
		while (tmp && i--)
			tmp = tmp->next;
	}
	return (back);
}

void	_sort_few(int size, t_list **stack_a, t_list **stack_b)
{
	int	front;
	int	back;

	while (_seq_len(*stack_a) < size - 1)
	{
		front = _front_end_few(*stack_a);
		back = _back_end_few(*stack_a);
		if (front <= size / 2 && front <= size - back)
			while (front--)
				_r(stack_a, 'a');
		else if (back > size / 2)
			while (back++ < size)
				_rr(stack_a, 'a');
		_pb(stack_a, stack_b);
		if ((*stack_b)->content < _min(*stack_a)
			|| (*stack_b)->content > _max(*stack_a))
			_lowtop(stack_a, 'a');
		else
			_slot_lowtop(stack_a, (*stack_b)->content, 'a');
		_pa(stack_a, stack_b);
	}
	_lowtop(stack_a, 'a');
}
