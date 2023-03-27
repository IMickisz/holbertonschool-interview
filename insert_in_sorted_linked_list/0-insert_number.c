#include "lists.h"

/**
 * insert_node -  inserts a number into a sorted singly linked list
 * @head: double pointer to the first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *tmp, *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		if (current->n > number)
		{
			new->next = *head;
			*head = new;
			return (new);
		}
		while (current->next && current->next->n < number)
			current = current->next;
		if (current->next == NULL)
		{
			current->next = new;
			new->next = NULL;
		}
		else
		{
			tmp = current->next;
			current->next = new;
			new->next = tmp;
		}
	}
	return (new);
}
