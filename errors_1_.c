#include "monty.h"

int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);

/**
 * usage_error - prints usge errors messages.
 * Return: (EXIT_FAILURE) Always
 */

int usage_error(void)
{
	fprintf(stderr, "usage: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * malloc_error - prints Malloc Error Messages.
 *
 * Return: (EXIT_FAILURE) Always.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * f_open_error - Prints file Opening error messages 
 * @filename: Name of file to open
 *
 * Return: (EXIT_FAILURE) Always.
 */
int f_open_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints Unknown Instruction Error messages.
 * @opcode: Opcode Where Error happened
 * @line_number: line Number 
 *
 * Return: (EXIT_FAILURE) Always.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - prints invalid monty_push Argument error messages.
 * @line_number: Line number 
 *
 * Return: (EXIT_FAILURE) Always.
 */
int no_int_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
