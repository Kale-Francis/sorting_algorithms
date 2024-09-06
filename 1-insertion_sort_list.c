#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;

    if (node2->prev == NULL)
        *list = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    current = (*list)->next;
    while (current)
    {
        temp = current;
        while (temp->prev && temp->n < temp->prev->n)
        {
            swap_nodes(list, temp->prev, temp);
            print_list(*list);  /* Print the list after every swap */
        }
        current = current->next;
    }
}
