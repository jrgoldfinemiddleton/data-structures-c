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


// aliases
typedef struct bag Bag;
typedef struct bag_node Node;


// Bag Node constructor

Node*           make_node(int val);


// API

Bag*            make_bag();
void            delete_bag(Bag* b);
void            add(Bag* b, int val);
bool            is_empty(Bag* b);
unsigned int    size(Bag* b);


#endif /* BAG_H */
