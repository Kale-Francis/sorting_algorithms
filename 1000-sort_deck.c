#include <stdlib.h>
#include "deck.h"
#include "sort.h"

/* Comparison function for qsort */
int compare_cards(const void *a, const void *b)
{
    const deck_node_t *node_a = *(const deck_node_t **)a;
    const deck_node_t *node_b = *(const deck_node_t **)b;
    const card_t *card_a = node_a->card;
    const card_t *card_b = node_b->card;

    if (card_a->kind != card_b->kind)
        return card_a->kind - card_b->kind;

    return card_a->value - card_b->value;
}

/* Sort the deck of cards */
void sort_deck(deck_node_t **deck)
{
    deck_node_t **array;
    deck_node_t *node;
    size_t i, size;

    /* Count the number of nodes in the list */
    for (node = *deck, size = 0; node; node = node->next, size++)
        ;

    /* Allocate memory for the array of pointers to nodes */
    array = malloc(size * sizeof(*array));
    if (!array)
        return;

    /* Fill the array with pointers to the nodes */
    for (node = *deck, i = 0; node; node = node->next, i++)
        array[i] = node;

    /* Sort the array of node pointers */
    qsort(array, size, sizeof(*array), compare_cards);

    /* Re-link the sorted nodes */
    for (i = 0; i < size - 1; i++)
    {
        array[i]->next = array[i + 1];
        array[i + 1]->prev = array[i];
    }
    array[0]->prev = NULL;
    array[size - 1]->next = NULL;
    *deck = array[0];

    free(array);
}
