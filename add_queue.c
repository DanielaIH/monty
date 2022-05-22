#include "monty.h"

/**
 * add_queue - adds a new node at the end of a sstack_t list.
 * @head: double pointer dlistint_t input
 * @n: const int input
 * Return: the address of the new element, or NULL if it failed
 */
sstack_t *add_queue(sstack_t **head, const int n)
{
	sstack_t *new, *aux;

	aux = *head;
	new = malloc(sizeof(sstack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	while (aux && aux->next)
		aux = aux->next;
	if (aux)
		aux->next = new, new->prev = aux;
	else
		*head = new, new->prev = NULL;
	return (new);
}
