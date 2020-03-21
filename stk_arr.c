#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

typedef struct Stack stk;

int isfull(stk *s);
int isempty(stk *s);
void push(stk *sk, int x);
int pop(stk *sk);
int peep(stk *sk, int pos);
void display(stk *sk);

int main(void)
{
    stk S;
    printf("Enter the size of the stack: ");
    scanf("%d", &S.size);

    S.s = (int *) malloc(S.size * sizeof(int));
    S.top = -1;

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
                push(&S, value);
                break;

            case 2:
                printf("Popped element from the stack: %d\n", pop(&S));
                break;

            case 3:
                printf("%s", "Enter the position: ");
                scanf("%d", &pos);
                printf("Element at %d: %d\n", pos, peep(&S, pos));
                break;

            case 4:
                display(&S);
                break;

            default:
                cont = 0;
        }
    }

    free(S.s);
    S.s = NULL;

    return 0;
}

int isfull(stk *sk)
{
    if (sk->top == sk->size - 1)
        return 1;
    return 0;
}

int isempty(stk *sk)
{
    if (sk->top == -1)
        return 1;
    return 0;
}

void push(stk *sk, int x)
{
    if (isfull(sk))
        puts("Stack is full.");
    else
    {
        sk->top++;
        sk->s[sk->top] = x;
    }    
}

int pop(stk *sk)
{
    if (isempty(sk))
    {
        puts("Stack is empty.");
        return INT_MIN;
    }
    
    int x = sk->s[sk->top];
    sk->top--;
    return x;      
}

int peep(stk *sk, int pos)
{
    if (isempty(sk))
    {
        puts("Stack is empty.");
        return INT_MIN;
    }
    
    if (sk->top - pos + 1 < 0 || pos >= sk->size)
    {
        puts("Position doesn't exists.");
        return INT_MIN;
    }
    
    return sk->s[sk->top - pos + 1];
}

void display(stk *sk)
{
    for (int i = 0; i <= sk->top; i++)
        printf("%d ", sk->s[i]);

    puts("");
}