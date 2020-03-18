#include <stdio.h>

double e(double x, int n);

int main(void)
{
    printf("%lf\n", e(1, 15));

    return 0;
}

double e(double x, int n)
{
    static double p = 1, f = 1;
    double r = 0;

    if (n == 0)
        return 1;
    else
    {
        r = e(x, n - 1);
        p *= x;
        f *= n;

        return r + p/f;
    }    
}

// Improved version using Horner's Rule
/*
double e(double x, int n)
{
    static double s = 1;

    if (n == 0)
        return s;
    s = 1 + x / n * s;

    return e(x, n - 1)
}
*/