#include "bag.h"

#include <stdio.h>


/* Test driver */
int main(void)
{
    struct bag *b = make_bag();
    struct bag_node *n;
    unsigned int pos = 0;
    int i;

    // print the size of new bag
    printf("size: %2u\n", size(b));

    // print size after adding each of 10 items
    for (i = 0; i != 10; ++i) {
        add(b, i);
        printf("size: %2u\n", size(b));
    }

    printf("\n");

    // print all items in bag
    n = b->top;
    while (n != NULL) {
        printf("item %2u: %2i\n", ++pos, n->item);
        n = n->next;
    }

    pos = 0;
    n = NULL;

    // deallocate the memory used by the bag and nodes
    delete_bag(b);

    return 0;
}
