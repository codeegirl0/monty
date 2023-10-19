#ifndef LOGS_H
#define LOGS_H

#include "monty.h"

/* first_list.c */
size_t thelistint_len(const listint_t *h);
listint_t *adding_nodeint(listint_t **head, const int n);
size_t printing_thelistint(const listint_t *h);
listint_t *get_node_atindex(listint_t *head, unsigned int index);
int del_node_atindex(listint_t **head, unsigned int index);

/* second_list.c */
listint_t *adding_nodeint_end(listint_t **head, const int n);
listint_t *push_node_atindex(listint_t **h, unsigned int idx, int n);
void freeing_thelists(listint_t *head);

#endif