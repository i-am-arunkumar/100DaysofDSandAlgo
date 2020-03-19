#include <stdio.h>

void merge(int a1[], int len1, int a2[], int len2);

int main(void)
{
    int a[] = {1, 4, 5, 6, 7};
    int b[] = {2, 3, 5, 6, 8, 9};

    merge(a, 5, b, 6);

    return 0;
}

void merge(int a1[], int len1, int a2[], int len2)
{
    int i, j, k;
    i = j = k = 0;

    int a3[len1 + len2];

    while (i < len1 && j < len2)
    {
        if (a1[i] < a2[j])
            a3[k++] = a1[i++];
        else
            a3[k++] = a2[j++];
    }

    for (; i < len1; i++)
        a3[k++] = a1[i];

    for (; j < len2; j++)
        a3[k++] = a2[j];

    puts("Merged array is: ");

    for (int l = 0; l < len1 + len2; l++)
        printf("%d ", a3[l]);

    puts("");
}