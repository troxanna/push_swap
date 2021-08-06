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
	struct s_stack	*next;
}				t_stack;

t_stack	*ft_elem_new(int number, unsigned int index);
void	ft_elem_add_back(t_stack **lst, t_stack *new);

#endif 