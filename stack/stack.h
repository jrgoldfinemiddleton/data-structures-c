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


// aliases
typedef struct stack Stack;
typedef struct stack_node Node;


// Stack Node constructor

Node*           make_node(int val);


// API

Stack*          make_stack();
void            delete_stack(Stack* s);
void            push(Stack* s, int val);
int             pop(Stack* s);
int             top(Stack* s);
bool            is_empty(Stack* s);
unsigned int    size(Stack* s);


#endif /* STACK_H */
