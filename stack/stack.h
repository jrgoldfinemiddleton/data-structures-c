#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Stack ADT

struct stack
{
    struct stack_node
    {
        int item;
        struct stack_node *next;
    } *top;

    unsigned int sz;
};

struct stack_node       *make_node(int val);

// API

struct stack            *make_stack();
void                    delete_stack(struct stack *s);
void                    push(struct stack *s, int val);
int                     pop(struct stack *s);
int                     top(struct stack *s);
bool                    is_empty(struct stack *s);
unsigned int            size(struct stack *s);

#endif /* STACK_H */
