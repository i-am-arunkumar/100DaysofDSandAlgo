#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

// node *create(int arr[], int size);
void display(node *list);
int count(node *list);
node *insert(node *list, int pos, int element);

int main(void)
{
    // int A[] = {3, 2, 5, 9, 6};

    // node *head = create(A, 5);

    node *head = (node *) malloc(sizeof(node));
    head = NULL;
    
    head = insert(head, 0, 3);
    head = insert(head, 1, 2);
    head = insert(head, 2, 5);
    head = insert(head, 3, 9);
    head = insert(head, 4, 6);

    display(head);

    printf("Number of nodes in the list: %d\n", count(head));

    insert(head, 3, 8);

    display(head);        

    free(head);

    return 0;
}

/*
node *create(int arr[], int size)
{
    node *first, *last, *temp;

    first = (node *) malloc(sizeof(node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < size; i++)
    {
        temp = (node *) malloc(sizeof(node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return first;
}
*/

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