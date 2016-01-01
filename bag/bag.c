#include "bag.h"

#include <stdlib.h>

// Bag Node constructor

Node* make_node(int val)
{
    Node *n = (Node*) malloc(sizeof(Node));
    n->item = val;
    n->next = NULL;

    return n;
}


// API

/* Constructs an empty bag on the heap. */
Bag* make_bag()
{
    Bag *b = (Bag*) malloc(sizeof(Bag));
    b->top = NULL;
    b->sz = 0;

    return b;
}


/* Deallocates the heap memory used by the bag and its nodes. */
void delete_bag(Bag* b)
{
    Node *n = b->top;

    // deallocate each node
    while (n != NULL)
    {
        Node *temp = n->next;
        free(n);
        n = temp;
    }

    // deallocate bag
    free(b);
}


/* Adds a new item to the bag. */
void add(Bag* b, int val)
{
    Node *new_top = make_node(val);
    new_top->next = b->top;
    b->top = new_top;
    ++(b->sz);
}


/* Returns true if the bag has no items, false otherwise. */
bool is_empty(Bag* b)
{
    return size(b) == 0U;
}


/* Returns the number of items in the bag. */
unsigned int size(Bag* b)
{
    return b->sz;
}
