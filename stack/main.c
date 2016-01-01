#include "stack.h"

#include <stdio.h>


/* Test driver */
int main(void)
{
    struct stack *s = make_stack();
    struct stack_node *n;
    unsigned int pos = 0;

    // print the size of new stack
    printf("size: %2u\n", size(s));
    printf("is empty? %i\n", is_empty(s));

    printf("trying to pop empty stack: %i\n", pop(s));

    // print size after adding each of 10 items
    for (int i = 0; i != 10; ++i)
    {
        push(s, i);
        printf("size: %2u\n", size(s));
    }

    printf("is empty? %i\n", is_empty(s));
    printf("\n");

    // print all items on stack
    n = s->top;
    while(n != NULL)
    {
        printf("item %2u: %2i\n", ++pos, n->item);
        n = n->next;
    }

    printf("top: %i\n", top(s));
    printf("popping top: %i\n", pop(s));
    printf("size: %u\n", size(s));
    printf("new top: %i\n", top(s));

    printf("pushing 5...\n");
    push(s, 5);
    printf("size: %u\n", size(s));
    printf("new top: %i\n", top(s));

    pos = 0;
    n = NULL;

    // deallocate the memory used by the stack and nodes
    delete_stack(s);

    return 0;
}
