//1. Индексируем: каждое число в стеке помечаем 0 или 1. 
//1.1. Берем любой элемент (вершину, н-р), помечаем ее 1. Смотрим следующий элемент - если он больше текущего - помечаем 1, если меньше - 0.
//Если пометили 0 и не обошли весь стек - сравниваем последнее число с 1 и следующий элемент, пока != 1.
//Проходим весь стека. 
//2. Повторяем шаг один, последовательно меняя вершину стека.
//3. Из проиндексированных стеков выбираем тот, где больше всего 1.
//4. Перемещаем все 0 в стек Б
//5. В стеке Б перебираем все числа и считаем для каждого числа количество команд (ra), которые необходимо будет сделать, чтобы поместить число из стека Б в нужное место в стеке А (между наименьшим и наиболльшим).
//6. Там где наименьшее количество команд - добавляем это число в стек А.
//7. Повторяем шаги 5- 6 для всех элементов стека А.

#include "push_swap.h"

int	set_number_index(t_stack *a, int count, int number)
{	
	int	i;
	t_stack	*ptr;
	int tmp_count;

	ptr = a;
	tmp_count = count - 1;
	i = -1;
	while (++i < count && ptr)
	{
		if (number < ptr->number)
			tmp_count--;
		ptr = ptr->next;
	}
	return (tmp_count);
}


void	number_item_markup(int count, t_stack *item, t_stack *head)
{
	int	*tmp_array;
	t_stack *ptr_head;
	unsigned int item_tmp;
	t_stack *ptr_current;
	int i;

	i = 0;
	ptr_head = head;
	ptr_current = item->next;
	// array = (int *)malloc(sizeof(int) * count);
	item->flag[0] = 1;
	item_tmp = item->index;
	//printf("\n\n%d\n\n", item_tmp);
	while (ptr_current)
	{
		if (item_tmp < ptr_current->index)
		{
			item->flag[++i] = 1;
			item_tmp = ptr_current->index;
		}
		else
			item->flag[++i] = 0; 
		ptr_current = ptr_current->next;
	}
	if (ptr_current && item_tmp < ptr_head->index)
	{
		item->flag[++i] = 1;
		item_tmp = ptr_current->index;
	}
	while (ptr_head->number != item->number)
	{
		if (item_tmp < ptr_head->index)
		{
			item->flag[++i] = 1;
			item_tmp = ptr_head->index;
		}
		else
			item->flag[++i] = 0; 
		ptr_head = ptr_head->next;
	}
}

int	count_item_true_elements(int *arr, int count)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = 0;
	while (++i < count)
	{
		if (arr[i] == 1)
			tmp++;
	}
	return (tmp);
}

// t_stack	*choose_optimal_stack(t_stack **t, int nb)
// {
// 	t_stack	*ptr;
// 	int		i;

// 	ptr = *t;
// 	i = 0;
// 	while (ptr->next)
// 	{
// 		if (!ptr->flag[i])
// 		{

// 		}
// 	}
// 	return (ptr);
// }

t_stack	*push_item_into_stack_b(t_stack *item, t_stack **b, t_stack **head)
{
	//пока item != *head
	//rotate_stack_cmd(t_stack **t)
	printf("number %d\n", item->number);
	return (item->next);
}

//передавать начало стека а
void	check_stack_a(int len, t_stack **a, t_stack **b, t_stack *head)
{
	t_stack	*ptr;
	int		i;

	ptr = head;
	i = 0;
	while (ptr)
	{
		if (!head->flag[i])
			ptr = push_item_into_stack_b(ptr, b);
		else
			ptr = ptr->next;
		i++;
	}
	if (head != *a)
	{
		ptr = *a;
		while (ptr != head)
		{
			if (!head->flag[i])
				ptr = push_item_into_stack_b(ptr, b);
			else
				ptr = ptr->next;
			i++;
		}
	}
}

// void	check_least_item_elements()

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_stack *ptr;
	t_stack *selected_head;
	int	i;
	int	count;
	int **array;

	i = -1;
	count = argc - 1;
	// array = (int **)malloc(sizeof(int *) * (count + 1));
	// array[count] = NULL;
	// while (++i < count)
	// 	array[i] = (int *)malloc(sizeof(int) * count);
	i = 1;
	a = ft_item_new(ft_atoi(argv[i]), 0);
	ptr = a;
	while (++i < argc)
		ft_item_add_back(&ptr, ft_item_new(ft_atoi(argv[i]), 0));
	while (ptr)
	{
		ptr->index = set_number_index(a, count, ptr->number);
		ptr = ptr->next;
	}
	ptr = a;
	i = -1;
	while (ptr)
	{
		ptr->flag = (int *)malloc(sizeof(int) * count);
		number_item_markup(count, ptr, a);
		ptr = ptr->next;
	}
	ptr = a;
	int	main_result;
	int	tmp_result;
	main_result = -1;
	selected_head = ptr;
	while (ptr)
	{
		tmp_result = count_item_true_elements(ptr->flag, count);
		if (main_result < tmp_result || (main_result == tmp_result && ptr->index < selected_head->index))
		{
			main_result = tmp_result;
			selected_head = ptr;
		}
		ptr = ptr->next;
	}
	printf("%d\n", selected_head->number);
	check_stack_a(count, &a, &b, selected_head);
	// int *result;

	// i = -1;
	// int j = -1;
	// ptr = a;
	// while (++i < count && ptr)
	// {
	// 	j = -1;
	// 	printf("number is: %d\n", ptr->number);
	// 	while (++j < count)
	// 	{
	// 		printf("array_index: %d\n", array[i][j]);
	// 	}
	// 	ft_putstr_fd("\n\n\n", 1);
	// 	ptr = ptr->next;
	// }
	// result = count_item_true_elements(array, count, a);
	// printf("max true is head with number: %d, count: %d, index: %d\n", result[1], result[0], result[2]);
	// a = choose_optimal_stack(&a, result[1]);
	// i = -1;
	// ptr = a;
	// while (ptr && array[result[2]][++i] < count)
	// {
	// 	if (array[result[2]][i] == 0)
	// 	{
	// 		push_item_into_stack_b(count, &a, i);
	// 	}
	// }
	// printf("stack number is: %d\n", a->number);
	// while (ptr && array[result[2]][++i])
	// {

	// }
	//b = ft_item_new(ft_atoi(argv[i]), 0);
	//if (b)
		//check_stack(b);
	//push_stack_cmd(&b, &a);
	//reverse_rotate_stack_cmd(&a);
	// fill_in_stack_b(a, result[1], array[result[0]], b);
	// i = -1;
	ptr = selected_head;
	i = 0;
	// while (ptr)
	// {
	// 	printf("number is: %d, ", ptr->number);
	// 	printf("index is: %d\n", selected_head->flag[i++]);
	// 	ptr = ptr->next;
	// }
	return (1);
}