#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

void display(node *list);
int count(node *list);
node *insert(node *list, int pos, int element);
node *insert_sorted(node *list, int element);
node *delete_node(node *list, int pos, int *element);

int main(void)
{
    node *head = (node *) malloc(sizeof(node));
    head = NULL;
    
    head = insert(head, 0, 1);
    head = insert(head, 1, 2);
    head = insert(head, 2, 5);
    head = insert(head, 3, 6);
    head = insert(head, 4, 9);

    display(head);

    printf("Number of nodes in the list: %d\n", count(head));

    head = insert_sorted(head, 4);

    display(head);

    int value = 0;
    head = delete_node(head, 5, &value);
    printf("The value at index 5 is: %d\n", value);
    display(head);        

    free(head);

    return 0;
}

void display(node *list)
{
    while (list)
    {
        printf("%d ", list->data);
        list = list->next;
    }

    puts("");
}

int count(node *list)
{
    int count = 0;

    while (list)
    {
        count++;
        list = list->next;
    }

    return count;
}

node *insert(node *list, int pos, int element)
{
    node *first = list;
    
    node *temp = (node *) malloc(sizeof(node));
    temp->data = element;
    temp->next = NULL;

    if (pos == 0)
    {
        temp->next = first;
        first = temp;
        return first;
    }

    for (int i = 0; i < pos - 1; i++)
        first = first->next;

    temp->next = first->next;
    first->next = temp;
    return list;
}

node *insert_sorted(node *list, int element)
{
    node *temp, *p = list, *q = NULL;

    temp = (node *) malloc(sizeof(node));
    temp->data = element;
    temp->next = NULL;

    if (list == NULL)
    {
        list = temp;
        return list;
    }
    
    while (p && p->data < element)
    {
        q = p;
        p = p->next;
    }

    if (p == list)
    {
        temp->next = p;
        list = temp;
        return list;
    }

    temp->next = q->next;
    q->next = temp;

    return list;
}

node *delete_node(node *list, int pos, int *element)
{
    node *p = list, *q = NULL;

    if (pos == 0)
    {
        list = p->next;
        *element = p->data; 
        free(p);
        return list;
    }

    for (int i = -1; i < pos - 1 && p; i++)
    {
        q = p;
        p = p->next;
    }

    if (p)
    {
        q->next = p->next;
        *element = p->data;
        free(p);
        return list;
    }
}