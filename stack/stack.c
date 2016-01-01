#include "stack.h"

#include <limits.h>
#include <stdlib.h>

// Stack Node constructor

Node* make_node(int val)
{
    Node *n = (Node*) malloc(sizeof(Node));
    n->item = val;
    n->next = NULL;

    return n;
}


// API

/* Constructs an empty stack on the heap. */
Stack* make_stack()
{
    Stack *s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->sz = 0;

    return s;
}


/* Deallocates the heap memory used by the stack and its nodes. */
void delete_stack(Stack* s)
{
    Node *n = s->top;

    // deallocate each node
    while (n != NULL)
    {
        Node *temp = n->next;
        free(n);
        n = temp;
    }

    // deallocate stack
    free(s);
}


/* Adds a new item to the top of the stack. */
void push(Stack* s, int val)
{
    Node *new_top = make_node(val);
    new_top->next = s->top;
    s->top = new_top;
    ++(s->sz);
}


/* Removes the top item from the stack and returns it.  If the stack
 * is empty, returns INT_MIN. */
int pop(Stack* s)
{
    if (s->top == NULL) return INT_MIN;

    int item = s->top->item;
    s->top = s->top->next;
    --(s->sz);

    return item;
}


/* Returns the top item from the stack.  If the stack is empty, returns
 * INT_MIN. */
int top(Stack* s)
{
    if (s->top == NULL) return INT_MIN;

    return s->top->item;
}


/* Returns true if the stack has no items, false otherwise. */
bool is_empty(Stack* s)
{
    return size(s) == 0U;
}


/* Returns the number of items on the stack. */
unsigned int size(Stack* s)
{
    return s->sz;
}
