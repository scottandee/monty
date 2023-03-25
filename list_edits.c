#include "monty.h"

/**
  * free_stack - this frees all the elements of the stack
  * @head: this is the head of the stack
  */

void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}

/**
  * add_node - this adds a new element at the top of a stack
  * @head: this is the first element on the stack
  * @n: this is the value that will be added to the stack
  */
void add_node(stack_t **head, const int n)
{
	stack_t *new_node, *temp;

	temp = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->n = n;
	if (temp)
	{
		temp->prev = new_node;
	}
		new_node->next = *head;
		*head = new_node;
}
