#include "monty.h"

/**
  * execute - this gets the correct op function code and executes
  * @line_num: this is the name of the operator
  * @stack: this is the first head of the stack
  * @content: this is the command
  * @file: this is the file descriptor
  * Return: pointer to operation if found or NULL if not
  */

int execute(char *content, stack_t **stack, unsigned int line_num, FILE *file)
{
	instruction_t f_names[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{NULL, NULL}
		};
	int i;
	char *op = NULL;

	op = strtok(content, " \n\t\r");
	var.value = strtok(NULL, " \n\t\r");

	i = 0;
	while (f_names[i].opcode && op != NULL)
	{
		if (strcmp(f_names[i].opcode, op) == 0)
		{
			f_names[i].f(stack, line_num);
			return (0);
		}
		i++;
	}
	if (op != NULL && f_names[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
