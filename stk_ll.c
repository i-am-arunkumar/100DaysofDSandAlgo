#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

int isempty(node *first);
int isfull(node *n);
node *push(node *first, int x);

int main(void)
{
    node *top = NULL;
    top = push(top, 5);
    top = push(top, 2);

    return 0;
}

int isempty(node *first)
{
    if (first == NULL)
        return 1;
    return 0;
}

int isfull(node *n)
{
    if (n == NULL)
        return 1;
    return 0;
}

node *push(node *first, int x)
{
    node *temp = (node *) malloc(sizeof(node));

    if (isfull(temp))
    {
        puts("The stack is full.");
        return NULL;
    }
    else
    {
        temp->data = x;
        temp->next = first;
        first = temp;
        return first;
    }    
}