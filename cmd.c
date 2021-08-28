#include "push_swap.h"

void	swap_stack_cmd(t_stack **t)
{
	t_stack	*tmp;

	if (!(*t) || !(*t)->next)
	{
		ft_putstr_fd("not enough items on the stack\n", 1);
		return ;
	}
	tmp = *t;
	*t = (*t)->next;
	(*t)->next = tmp;
}

void	push_stack_cmd(t_stack **t_first, t_stack **t_second)
{
	if (!(*t_second))
	{
		ft_putstr_fd("not enough items in the second stack\n", 1);
		return ;
	}
	ft_item_add_front(t_first, *t_second);
	(*t_second) = delete_head(*t_second);
}

void	rotate_stack_cmd(t_stack **t)
{
	t_stack	*tmp;

	if (!(*t) || !(*t)->next)
	{
		ft_putstr_fd("not enough items on the stack\n", 1);
		return ;
	}
	tmp = *t;
	while ((*t)->next)
		*t = (*t)->next;
	tmp->next = NULL;
	(*t)->next = tmp;
}

void	reverse_stack_cmd(t_stack **t)
{
	t_stack	*tmp;
	t_stack	*ptr;
	t_stack	*ptr_t;

	if (!(*t) || !(*t)->next)
	{
		ft_putstr_fd("not enough items on the stack\n", 1);
		return ;
	}
	ptr = (*t);
	tmp = (*t);
	while (ptr->next->next)
		ptr = ptr->next;
	*t = ptr->next;
	ptr->next = NULL;
	(*t)->next = tmp;
}