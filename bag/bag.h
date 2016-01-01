#ifndef BAG_H
#define BAG_H

#include <stdbool.h>

// Bag ADT

struct bag
{
    struct bag_node
    {
        int item;
        struct bag_node *next;
    } *top;

    unsigned int sz;
};

struct bag_node     *make_node(int val);

// Bag API

struct bag          *make_bag();
void                delete_bag(struct bag *b);
void                add(struct bag *b, int val);
bool                is_empty(struct bag *b);
unsigned int        size(struct bag *b);

#endif /* BAG_H */
