#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

int isempty(node *first);
int isfull(node *n);
node *push(node *first, int x);
node *pop(node *first, int *x);
int peep(node *first, int pos);
void display(node *first);

int main(void)
{
    node *top = NULL;
    
    int cont = 1;

    while (cont)
    {
        puts("1. push\n2. pop\n3. peep\n4. display\nPress any other key to exit");

        int choice, value, pos;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
                printf("%s", "Enter the number to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;

            case 2:
                top = pop(top, &value);
                printf("Popped element from the stack: %d\n", value);
                break;

            case 3:
                printf("%s", "Enter the position: ");
                scanf("%d", &pos);
                printf("Element at %d: %d\n", pos, peep(top, pos));
                break;

            case 4:
                display(top);
                break;

            default:
                cont = 0;
        }
    }

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

node *pop(node *first, int *x)
{
    node *temp = first;
    
    if (isempty(first) == 1)
    {
        puts("The stack is empty.");
        return NULL;
    }

    *x = first->data;
    first = temp->next;
    free(temp);

    return first;
}

int peep(node *first, int pos)
{
    if (isempty(first) == 1)
    {
        puts("The stack is empty.");
        return INT_MIN;
    }

    for (int i = 1; i < pos; i++)
        first = first->next;

    return first->data;
}

void display(node *first)
{
    while (first)
    {
        printf("%d ", first->data);
        first = first->next;
    }

    puts("");
}