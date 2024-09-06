#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: Left node to swap
 * @right: Right node to swap
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (left->prev)
        left->prev->next = right;
    else
        *list = right;

    if (right->next)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;
    left->prev = right;
    right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
        swapped = 0;
        current = *list;

        /* Traverse from left to right */
        while (current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
            }
            else
            {
                current = current->next;
            }
        }

        /* If no elements were swapped, the list is sorted */
        if (!swapped)
            break;

        swapped = 0;

        /* Traverse from right to left */
        while (current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                print_list(*list);
                swapped = 1;
            }
            else
            {
                current = current->prev;
            }
        }

    } while (swapped);
}
