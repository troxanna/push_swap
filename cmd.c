#include "push_swap.h"

//swap the first 2 elements at the top of stack.
void	swap_stack_cmd(t_stack **t)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!(*t) || !(*t)->next)
	{
		ft_putstr_fd("not enough items on the stack\n", 1);
		return ;
	}
	tmp = *t;
	*t = (*t)->next;
	tmp2 = (*t)->next;
	(*t)->prev = NULL;
	(*t)->next = tmp;
	tmp->prev = (*t);
	tmp->next = tmp2;
}

//take the first element at the top of second stack and put it at the top of first stack.
void	push_stack_cmd(t_stack **t_first, t_stack **t_second)
{
	if (!(*t_second))
	{
		ft_putstr_fd("not enough items in the second stack\n", 1);
		return ;
	}
	ft_item_add_front(t_first, ft_item_new((*t_second)->number, (*t_second)->index));
	(*t_second) = delete_head(*t_second);
}

// shift up all elements of stack by 1. The first element becomes the last one.
void	rotate_stack_cmd(t_stack **t)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if (!(*t) || !(*t)->next)
	{
		ft_putstr_fd("not enough items on the stack\n", 1);
		return ;
	}
	tmp = *t;
	(*t) = (*t)->next;
	(*t)->prev = NULL;
	ptr = *t;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = tmp;
	tmp->prev = ptr;
	tmp->next = NULL;
}

//shift down all elements of stack by 1. The last element becomes the first one.
void	reverse_rotate_stack_cmd(t_stack **t)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*ptr;

	tmp = *t;
	if (!(*t) || !(*t)->next) 
	{
		ft_putstr_fd("not enough items on the stack\n", 1);
		return ;
	}
	ptr = *t;
	while (ptr->next)
		ptr = ptr->next;
	*t = ptr;
	tmp2 = ptr->prev;
	tmp2->next = NULL;
	(*t)->prev = NULL;
}