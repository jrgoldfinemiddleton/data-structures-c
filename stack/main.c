#include "stack.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct stack_node *n;
    struct stack      *s;
    int               i;
    int               item;

    int vals[10] = { 2, 0, -1, 5, 6, 2, 7, 9, 100, -40 };

    /* test make_node() */
    n = NULL;
    n = make_node(vals[2]);

    assert(n != NULL);
    assert(n->item == vals[2]);
    assert(n->next == NULL);

    free(n);
    n = NULL;

    /* test make_stack() */
    s = NULL;
    s = make_stack();

    assert(s != NULL);

    /* test is_empty(), size(), pop(), push(), and top() */
    assert(is_empty(s));
    assert(size(s) == 0);
    assert(pop(s) == INT_MIN);

    push(s, vals[0]);
    assert(!is_empty(s));
    assert(size(s) == 1);

    item = top(s);
    assert(size(s) == 1);
    assert(item == vals[0]);

    item = pop(s);
    assert(size(s) == 0);
    assert(item == vals[0]);

    n = s->top;
    assert(n == NULL);

    push(s, vals[1]);
    assert(!is_empty(s));
    assert(size(s) == 1);

    n = s->top;
    assert(n != NULL);
    assert(n->item == vals[1]);
    assert(n->next == NULL);

    for (i = 2; i != 10; ++i)
        push(s, vals[i]);

    assert(size(s) == 9);

    delete_stack(s);

    puts("OK");

    return 0;
}



