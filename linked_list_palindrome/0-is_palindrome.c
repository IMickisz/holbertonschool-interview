#include "lists.h"

/**
 * is_palindrome - Function that checks if a singly linked list is a palindrome
 * @head: head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
	int list[1000000];
	long n = 0, i;
	listint_t *node;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (1);
	if ((*head)->next == NULL)
		return (1);

	node = *head;
	while (node != NULL)
	{
		list[n] = node->n;
		node = node->next;
		n++;
	}
	for (i = 0; i < (n / 2); i++)
	{
		if (list[i] != list[n - i - 1])
			return (0);
	}
	return (1);
}
