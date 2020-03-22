#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

struct Queue
{
    node *front;
    node *rear;
    int count;
};

typedef struct Queue queue;

int isfull(node *t);
int isempty(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
int peep(queue *q, int pos);
void display(queue *q);
void release(queue *q);

int main(void)
{
    queue Q;
    Q.front = Q.rear = NULL;
    Q.count = 0;

    while (1)
    {
        puts("1. enqueue 2. dequeue 3. peep 4. display 5. To exit");

        int choice, value, pos;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
                printf("%s", "Enter the number to enqueue: ");
                scanf("%d", &value);
                enqueue(&Q, value);
                break;

            case 2:
                printf("Dequeued element from the queue: %d\n", dequeue(&Q));
                break;

            case 3:
                printf("%s", "Enter the position: ");
                scanf("%d", &pos);
                printf("Element at %d: %d\n", pos, peep(&Q, pos));
                break;

            case 4:
                display(&Q);
                break;

            case 5:
                release(&Q);
                return 0;
                break;

            default:
                exit(1);
        }
    }    
}

int isfull(node *t)
{
    if (t == NULL)
        return 1;
    return 0;
}

int isempty(queue *q)
{
    if (q->front == q->rear && q->front == NULL)
        return 1;
    return 0;
}

void enqueue(queue *q, int x)
{
    node *temp = (node *) malloc(sizeof(node));

    if (isfull(temp))
    {
        puts("Queue is full.");
        return;
    }

    temp->data = x;
    temp->next = NULL;

    if (isempty(q))
    {       
        q->front = q->rear = temp;
        q->count++;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
    q->count++;
}

int dequeue(queue *q)
{
    if (isempty(q))
    {
        puts("Queue is empty.");
        return INT_MIN;
    }

    int x = q->front->data;
    node *temp = q->front;
    q->front = q->front->next;
    q->count--;
    free(temp);

    return x;
}

int peep(queue *q, int pos)
{
    if (isempty(q))
    {
        puts("Queue is empty.");
        return INT_MIN;
    }

    if (pos > q->count)
    {
        puts("The required doesn't exits.");
        return INT_MIN;
    }

    node *p = q->front;

    for (int i = 0; i < pos - 1; i++)
        p = p->next;

    return p->data;
}

void display(queue *q)
{
    node *p = q->front;

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p);

    puts("");    
}

void release(queue *q)
{
    node *temp;

    do
    {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    } while (q->front != q->rear);

    temp = q->front;
    q->front = q->rear = NULL;
    free(temp);    
}