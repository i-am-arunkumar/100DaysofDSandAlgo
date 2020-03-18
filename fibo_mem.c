// fibonacci series using memoization

#include <stdio.h>

long int F[100];

long int fibo(int n);

int main(void)
{
    for (int i = 0; i < 100; i++)
        F[i] = -1;
    
    printf("%Li\n", fibo(9));
    
    return 0;
}

long int fibo(int n)
{
    if (n <= 2)
    {
        F[n] = n - 1;
        return F[n];
    }
    else
    {
        if (F[n - 1] == -1)
            F[n - 1] = fibo(n - 1);
        if (F[n - 2] == -1)
            F[n - 2] = fibo(n - 2);

        return F[n - 1] + F[n - 2];
    }    
}