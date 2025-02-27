// dynamic_array.h
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;      // Pointer to array elements
    size_t size;    // Number of elements
    size_t capacity; // Allocated memory size
} DynamicArray;

/* 
Creates a new DynamicArray with an initial capacity
- Allocates memory for the `DynamicArray` struct itself
- Allocates memory for the `data` array inside the struct
- Initializes `size` to 0 and `capacity` to the given parameter
*/
DynamicArray *create_array(size_t capacity);

/* 
Appends a new element to the end of the array
- If the array is full (`size == capacity`), it doubles the allocated memory (`capacity *= 2`)
- Adds the new value at the end of the array
- Increments `size` to reflect the new element
*/
void append(DynamicArray *arr, int value);

/*
Inserts an element at the specified index, shifting existing elements right
- If index is out of bounds (index > size), does nothing
- If the array is full, it resizes (doubles capacity)
- Shifts elements to the right to make space
- Places the new value at index and increments size 
*/
void insert(DynamicArray *arr, size_t index, int value);

/*
Deletes an element at the specified index, shifting elements left
- If index is out of bounds ( index >= size ), does nothing
- Shifts elements to the left to overwrite the deleted element
- Decrements size 
*/
void delete(DynamicArray *arr, size_t index);

/*
Retrieves the element at the given index.
- If index is out of bounds ( index >= size ), returns -1 (error case).
- Otherwise, returns the element at data[index] .
*/
int get(DynamicArray *arr, size_t index);

/*
Frees the memory allocated for the dynamic array.
- First frees data (the internal array).
- Then frees arr (the struct itself).
*/
void free_array(DynamicArray *arr);

/*
Prints the contents of the array.
- Displays elements in a [ value1 value2 ... ] format.
*/
void print_array(DynamicArray *arr);

#endif // DYNAMIC_ARRAY_H
