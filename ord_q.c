#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
    int count;
};

typedef struct Queue queue;

int isfull(queue *qe);
int isempty(queue *qe);
void enqueue(queue *qe, int x);
int dequeue(queue *qe);
int peep(queue *qe, int x);
void display(queue *qe);

int main(void)
{
    queue Q;
    printf("%s", "Enter the size of the queue: ");
    scanf("%d", &Q.size);

    Q.front = Q.rear = -1;
    Q.count = 0;

    Q.arr = (int *) malloc(Q.size * sizeof(int));
    
    int cont = 1;

    while (cont)
    {
        puts("1. enqueue\n2. deque\n3. peep\n4. display\nPress any other key to exit");

        int choice, value, pos;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: 
                printf("%s", "Enter the number to push: ");
                scanf("%d", &value);
                enqueue(&Q, value);
                break;

            case 2:
                printf("Popped element from the stack: %d\n", dequeue(&Q));
                break;

            case 3:
                printf("%s", "Enter the position: ");
                scanf("%d", &pos);
                printf("Element at %d: %d\n", pos, peep(&Q, pos));
                break;

            case 4:
                display(&Q);
                break;

            default:
                cont = 0;
                break;
        }
    }

    free(Q.arr);
    Q.arr = NULL;
    return 0;
}

int isfull(queue *qe)
{
    if (qe->rear == qe->size - 1)
        return 1;
    return 0;
}

int isempty(queue *qe)
{
    if (qe->front == qe->rear)
        return 1;
    return 0;
}

void enqueue(queue *qe, int x)
{
    if (isfull(qe))
    {
        puts("Queue is full.");
        return;
    }

    qe->rear++;
    qe->arr[qe->rear] = x;
    qe->count++;
}

int dequeue(queue *qe)
{
    if (isempty(qe))
    {
        puts("Queue is empty.");
        return INT_MIN;
    }

    qe->front++;
    qe->count--;
    return qe->arr[qe->front];
}

void display(queue *qe)
{
    for (int i = qe->front + 1; i <= qe->rear; i++)
        printf("%d ", qe->arr[i]);
    puts("");
}

int peep(queue *qe, int x)
{
    if (isempty(qe))
    {
        puts("Queue is empty.");
        return INT_MIN;
    }

    return qe->arr[qe->front + x];
}