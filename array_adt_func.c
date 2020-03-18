#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

typedef struct Array arr;

void die(char *s)
{
    printf("%s\n", s);

    exit(1);
}

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

arr create_array(arr p_a,int p_size)
{
    p_a.A = (int *) malloc(p_size * sizeof(int));
    p_a.size = p_size;

    return p_a;
}

void initialize(arr *p_a, int p_size)
{
    int n;
    printf("%s", "Enter number of elements in the array: ");
    scanf("%d", &n);

    if (n > p_size)
        die("Number of elements exceeds the size of the array.");

    puts("Enter the elements of the array: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &p_a->A[i]);

    p_a->length = n;
}

void display(arr p_a)
{
    for (int i = 0; i < p_a.length; i++)
        printf("%d ", p_a.A[i]);

    puts("");
}

void append(arr *p_a, int p_element)
{
    if (p_a->length == p_a->size)
        die("There is no space in array to append the element.");
    
    p_a->A[p_a->length] = p_element;
    p_a->length++;
}

void insert(arr *p_a, int p_index, int p_element)
{
    if (p_index < 0 && p_index >= p_a->length)
        die("The required index is out of bound.");

    for (int i = p_a->length; i > p_index; i--)
        p_a->A[i] = p_a->A[i - 1];

    p_a->A[p_index] = p_element;
    p_a->length++;
}

int delete(arr *p_a, int p_index)
{
    if (p_index < 0 && p_index >= p_a->length)
        die("The required index is out of bound.");
    
    int x = p_a->A[p_index];

    for (int i = p_index; i < p_a->length - 1; i++)
        p_a->A[i] = p_a->A[i + 1];

    p_a->length--;

    return x;
}

int linear_search(arr *p_a, int p_key)
{
    for (int i = 0; i < p_a->length; i++)
    {
        if (p_a->A[i] == p_key)
        {
            swap(&p_a->A[i], &p_a->A[i - 1]);
            return i - 1;
        }
    }

    return -1;
}

int binary_search(arr *p_a, int p_key)
{
    int l = 0, h = p_a->length - 1;
    int mid;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (p_a->A[mid] == p_key)
            return mid;
        else if (p_key < p_a->A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}