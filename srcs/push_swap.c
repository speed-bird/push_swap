/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:21 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/21 11:53:23 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_solve(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 3)
		_sort_three(stack_a);
	else if (size > 3 && size <= 10)
		_sort_medium(size, stack_a, stack_b);
	else if (size > 10)
		_sort_large(size, stack_a, stack_b);
	_lowtop(stack_a, 'a');
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!_valid_input(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc <= 2)
		return (0);
	i = 0;
	while (++i < argc)
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
	if (ft_lstsize(stack_a) < argc - 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	_solve(&stack_a, &stack_b);
}
