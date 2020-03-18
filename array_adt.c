#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

typedef struct Array arr;

void die(char *s);
arr create_array(arr p_a,int p_size);
void initialize(arr *p_a, int p_size);
void append(arr *p_a, int p_element);
void display(arr p_a);

int main(void)
{
    int size;
    printf("%s", "Enter the size of the array: ");
    scanf("%d", &size);

    arr A;
    A = create_array(A, size);

    initialize(&A, size);

    display(A);

    printf("%s", "Enter the element to append: ");
    int element;
    scanf("%d", &element);

    append(&A, element);

    display(A);

    free(A.A);

    return 0;
}

void die(char *s)
{
    printf("%s\n", s);

    exit(1);
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