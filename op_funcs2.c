#include "monty.h"

/**
  * _swap - this swaps the top two elements on the stack
  * @stack: this is the head of the stack
  * @line_number: ths is the line number
  */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int length = 0, n, m;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	n = temp->n;
	temp = temp->next;
	m = temp->n;
	temp->n = n;
	temp = temp->prev;
	temp->n = m;
}

