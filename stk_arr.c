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

    push(&S, 4);
    push(&S, 6);
    push(&S, 9);

    printf("Value at position 2 is %d\n", peep(&S, 2));

    display(&S);

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