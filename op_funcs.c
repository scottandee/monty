#include "monty.h"

/**
  * _push - this adds an element to the top of the stack
  * @stack: this is the first element of a stack
  * @line_number: this is the line number
  */

void _push(stack_t **stack, unsigned int line_number)
{
	int i = 0, flag = 0, n = 0;

	if (var.value != NULL)
	{
		if (var.value[0] == '-')
		{
			i++;
		}
		for (; var.value[i] != '\0'; i++)
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

/**
  * _pint - this prints the element at the top of the stack
  * @stack: this is the head of the stack
  * @line_number: this is line number
  */
void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}

/**
  * _pop - removes the top element of the stack
  * @stack: this is the head of the stack
  * @line_number: this is the line number
  */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(var.file);
		free(var.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	free(temp);
}
