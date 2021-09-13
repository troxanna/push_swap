#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int	number;
	unsigned int	index;
	int				*flag;
	int				region; // оперделять в какой части стека
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

t_stack	*ft_item_new(int number, unsigned int index);
void	ft_item_add_front(t_stack **lst, t_stack *new);
void	ft_item_add_back(t_stack **lst, t_stack *new);
void	swap_stack_cmd(t_stack **t);
t_stack	*delete_head(t_stack *root);
void	rotate_stack_cmd(t_stack **t);
void	reverse_rotate_stack_cmd(t_stack **t);
void	check_stack(t_stack *t);
void	push_stack_cmd(t_stack **t_first, t_stack **t_second);

#endif 