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

int main(void)
{
    queue Q;
    Q.front = Q.rear = NULL;
    Q.count = 0;

    enqueue(&Q, 4);
    enqueue(&Q, 8);
    enqueue(&Q, 2);
    enqueue(&Q, 7);
    dequeue(&Q);
    dequeue(&Q);

    return 0;
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
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
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
    free(temp);

    return x;
}