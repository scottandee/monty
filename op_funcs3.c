#include "monty.h"
/**
  * _mul - this adds the two top elements of the stack
  * @stack:  this is the head of the stack
  * @line_number: this is te line number
  */

void _mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	a = temp->n;
	b = temp->next->n;
	temp->next->n = a * b;
	*stack = temp->next;
	free(temp);
}
/**
  * _mod - this adds the two top elements of the stack
  * @stack:  this is the head of the stack
  * @line_number: this is te line number
  */

void _mod(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	a = temp->n;
	b = temp->next->n;
	temp->next->n = b % a;
	*stack = temp->next;
	free(temp);
}
