#include "stack.h"

#include <limits.h>
#include <stdlib.h>

/*
 * Constructs a new node.
 */
struct stack_node *make_node(int val)
{
    struct stack_node *n;

    n = (struct stack_node*) malloc(sizeof(struct stack_node));
    n->item = val;
    n->next = NULL;

    return n;
}


// Stack API

/*
 * Constructs an empty stack on the heap.
 */
struct stack *make_stack()
{
    struct stack *s;

    s = (struct stack*) malloc(sizeof(struct stack));
    s->top = NULL;
    s->sz = 0;

    return s;
}


/*
 * Deallocates the heap memory used by the stack and its nodes.
 */
void delete_stack(struct stack *s)
{
    struct stack_node *n;
    struct stack_node *tmp;

    n = s->top; /* current node */

    // deallocate each node
    while (n != NULL) {
        tmp = n->next;
        free(n);
        n = tmp;
    }

    free(s);
}


/*
 * Adds a new item to the top of the stack.
 */
void push(struct stack *s, int val)
{
    struct stack_node *new_top;
    
    new_top = make_node(val); /* new node */
    new_top->next = s->top;
    s->top = new_top;
    ++(s->sz);
}


/*
 * Removes the top item from the stack and returns it.  If the stack
 * is empty, returns INT_MIN.
 */
int pop(struct stack *s)
{
    int item;
    struct stack_node *old_top;

    if (s->top == NULL) return INT_MIN;

    old_top = s->top;
    item = old_top->item;    /* store item */

    s->top = old_top->next;
    free(old_top);
    --(s->sz);

    return item;
}


/*
 * Returns the top item from the stack.  If the stack is empty, returns
 * INT_MIN.
 */
int top(struct stack *s)
{
    if (s->top == NULL) return INT_MIN;

    return s->top->item;
}


/*
 * Returns true if the stack has no items, false otherwise.
 */
bool is_empty(struct stack *s)
{
    return size(s) == 0U;
}


/*
 * Returns the number of items on the stack.
 */
unsigned int size(struct stack *s)
{
    return s->sz;
}
