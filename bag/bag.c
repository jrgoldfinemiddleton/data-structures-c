#include "bag.h"

#include <stdlib.h>

/* 
 * Constructs a bag node.
 */
struct bag_node *make_node(int val)
{
    struct bag_node *n;
    
    n = (struct bag_node*) malloc(sizeof(struct bag_node));
    n->item = val;
    n->next = NULL;

    return n;
}


// Bag API

/*
 * Constructs an empty bag on the heap.
 */
struct bag *make_bag()
{
    struct bag *b;

    b = (struct bag*) malloc(sizeof(struct bag));
    b->top = NULL;
    b->sz = 0;

    return b;
}


/*
 * Deallocates the heap memory used by the bag and its nodes.
 */
void delete_bag(struct bag *b)
{
    struct bag_node *n;
    struct bag_node *tmp;
    
    n = b->top; /* current node */

    // deallocate each node
    while (n != NULL) {
        tmp = n->next;
        free(n);
        n = tmp;
    }

    free(b);
}


/*
 * Adds a new item to the bag.
 */
void add(struct bag *b, int val)
{
    struct bag_node *new_top;
    
    new_top = make_node(val); /* new node */
    new_top->next = b->top;
    b->top = new_top;
    ++(b->sz);
}


/*
 * Returns true if the bag has no items, false otherwise.
 */
bool is_empty(struct bag *b)
{
    return size(b) == 0U;
}


/* 
 * Returns the number of items in the bag.
 */
unsigned int size(struct bag *b)
{
    return b->sz;
}
