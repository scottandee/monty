#include "monty.h"

/**
  * _push - this adds an element to the top of the stack
  * @stack: this is the first element of a stack
  * @line_number: this is the line number
  */

void _push(stack_t **stack, unsigned int line_number)
{
	int i, flag = 0, n = 0;

	if (var.value != NULL)
	{
		for (i = 0; var.value[i] != '\0'; i++)
		{
			if (var.value[i] > 57 || var.value[i] < 48)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(var.file);
			free(var.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = atoi(var.value);
	add_node(stack, n);
}

/**
  * _pall - this prints all the elements on the stack
  * @stack: this is stack that the element will be added to
  * @line_number: this is the line number
  */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
