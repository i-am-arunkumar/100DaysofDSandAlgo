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

    printf("%s", "Enter the element to insert at 2: ");
    int element;
    scanf("%d", &element);

    // append(&A, element);
    insert(&A, 2, element);

    display(A);

    // insert(&A, 4, 12);

    // display(A);

    // delete(&A, 4);

    // display(A);

    // printf("%d\n", linear_search(&A, 3));
    // printf("%d\n", linear_search(&A, 19));

    printf("Element at index 4: %d\n", get(&A, 4));
    // set(&A, 3, 2);

    display(A);

    printf("Max: %d\n", max(&A));
    printf("Min: %d\n", min(&A));

    printf("Avg: %d\n", avg(&A));

    // reverse(&A);

    // display(A);

    // rotate(&A, 'l');

    // display(A);

    // rotate(&A, 'r');

    insert_sort(&A, 4);

    display(A);

    is_sorted(&A);

    part(&A);

    display(A);

    free(A.A);

    return 0;
}