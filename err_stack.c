#include "monty.h"
#include <string.h>

int check_mode(stack_t *stack);
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);

/**
 * free_stack - it frees  stack_t stack.
 * @stack: ptr to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - It initializes a stack_t stack with beginning
 *              stack and ending queue nodes
 * @stack: ptr to an unitialized stack_t stack.
 *
 * Return: on Error return - EXIT_FAILURE.
 *         else - EXIT_SUCCESS.
 */

int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - it Checks if  stack_t linked list is in stack or queue mode.
 * @stack: A ptr to top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: ifstack_t is in stack mode - STACK (0).
 *         if the stack_t is in (queue) mode - QUEUE (1).
 *         else - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
