#include <stdio.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

int max(node *list)
{
    if (!list)
        return INT_MIN;
    x = max(list->next);

    return x > list->data ? x : list->data;
}

node *search(node *list, int key)
{
    if (!list)
        return NULL;
    if (list->data == key)
        return list;
    return search(list->next);
}