#include "monty.h"

/**
 * add_stack - adds a new node at the beginning of a sstack_t list.
 * @head: double pointer dlistint_t input
 * @n: const int input
 * Return: the address of the new element, or NULL if it failed
 */
sstack_t *add_stack(sstack_t **head, const int n)
{
	sstack_t *new, *aux;

	aux = *head;
	new = malloc(sizeof(sstack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	if (!aux)
		new->next = NULL;
	else
	{
		while (aux->prev)
			aux = aux->prev;
		aux->prev = new;
		new->next = aux;
	}
	*head = new;
	return (*head);
}
