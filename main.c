// main.c
#include <stdio.h>
#include "dynamic_array.h"

int main() {
    DynamicArray *arr = create_array(2);

    append(arr, 10);
    append(arr, 20);
    append(arr, 30);  // This should trigger a resize

    printf("Array after appends: ");
    print_array(arr); // Output: [ 10 20 30 ]

    insert(arr, 1, 99);
    printf("Array after insert at index 1: ");
    print_array(arr); // Output: [ 10 99 20 30 ]

    delete(arr, 2);
    printf("Array after deleting index 2: ");
    print_array(arr); // Output: [ 10 99 30 ]

    printf("Element at index 1: %d\n", get(arr, 1)); // Output: 99

    free_array(arr);
    return 0;
}