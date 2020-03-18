#include <stdio.h>
#include <stdlib.h>
#include "array_adt_func.h"

struct Array
{
    int *A;
    int size;
    int length;
};

typedef struct Array arr;

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

    insert(&A, 4, 12);

    display(A);

    delete(&A, 4);

    display(A);

    printf("%d\n", binary_search(&A, 3));
    printf("%d\n", binary_search(&A, 19));

    free(A.A);

    return 0;
}