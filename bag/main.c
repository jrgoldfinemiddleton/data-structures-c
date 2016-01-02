#include "bag.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct bag_node *n;
    struct bag      *b;
    int              i;

    int vals[10] = { 2, 0, -1, 5, 6, 2, 7, 9, 100, -40 };

    /* test make_node() */
    n = NULL;
    n = make_node(vals[2]);

    assert(n != NULL);
    assert(n->item == vals[2]);
    assert(n->next == NULL);

    free(n);
    n = NULL;

    /* test make_bag() */
    b = NULL;
    b = make_bag();

    assert(b != NULL);

    /* test is_empty(), size(), and add() */
    assert(is_empty(b));
    assert(size(b) == 0);

    add(b, vals[0]);
    assert(!is_empty(b));
    assert(size(b) == 1);

    n = b->top;
    assert(n != NULL);
    assert(n->item == vals[0]);
    assert(n->next == NULL);

    add(b, vals[1]);
    assert(!is_empty(b));
    assert(size(b) == 2);

    n = b->top;
    assert(n != NULL);
    assert(n->item == vals[1]);
    assert(n->next != NULL);
    assert(n->next->item == vals[0]);

    for (i = 2; i != 10; ++i)
        add(b, vals[i]);

    assert(size(b) == 10);

    delete_bag(b);

    puts("OK");

    return 0;
}



