#include "monty.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

char **op_toks = NULL;

/**
 * main - Entry point (Monty Interp)
 * @argc: Count of arguments passed to the program
 * @argv: ptr to (array) of char pointers to arguments
 *
 * Return: On success(EXIT_SUCCESS) On Error (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int exit_code = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");
	if (script_fd == NULL)
		return (f_open_error(argv[1]));
	exit_code = run_monty(script_fd);
	fclose(script_fd);
	return (exit_code);
}
