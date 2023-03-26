#include "monty.h"

/**
  * _swap - this swaps the top two elements on the stack
  * @stack: this is the head of the stack
  * @line_number: ths is the line number
  */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int length = 0, n;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	n = temp->n;
	temp->n = temp->next->n;
	temp->next->n = n;
}

/**
  * _add - this adds the two top elements of the stack
  * @stack:  this is the head of the stack
  * @line_number: this is te line number
  */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int length = 0, a, b;

	temp = *stack;
	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	a = temp->n;
	b = temp->next->n;
	temp->next->n = a + b;
	*stack = temp->next;
	free(temp);
}

/**
  * _nop - this doesn't do anything
  * @stack: this is the head of the stack
  * @line_number: this is the line number
  */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

