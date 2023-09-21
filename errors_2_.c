#include "monty.h"

int pop_error(unsigned int line_number);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);

/**
 * pop_error -outputs pop Error Messages for Empty stacks.
 * @line_number: Line number in script where error happened.
 * Return: (EXIT_FAILURE) Always
 */

int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - outputs pint error messages for empty stacks.
 * @line_number: Line number in Monty bytecodes file where error happened
 *
 * Return: (EXIT_FAILURE) Always.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error -outputs monty math Function error messages
 *                     for stacks/queues Smaller than two nodes.
 * @line_number: Line number in Monty bytecodes file where errorhappened
 * @op: operation where the error happened
 *
 * Return: (EXIT_FAILURE) Always.
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error -outputs division Error messages for division by 0.
 * @line_number: Line number in Monty bytecodes file where error happened
 *
 * Return: (EXIT_FAILURE) Always.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - outputs Pchar error messages for empty stacks
 *               empty stacks and non-character values.
 * @line_number: Line number in Monty bytecodes
 * @message: Corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) Always.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
