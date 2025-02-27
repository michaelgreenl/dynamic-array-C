#include "dynamic_array.h"

DynamicArray *create_array(size_t capacity) {
  int *n = (int *)malloc(sizeof(int));
  DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
  free(n);

  if (!arr) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  arr->data = (int *)malloc(capacity * sizeof(int));

  if (!arr->data) {
    printf("Memory allocation failed\n");
    free(arr);
    return NULL;
  }

  arr->size = 0;
  arr->capacity = capacity;
  return arr;
}

void append(DynamicArray *arr, int value) {
  if (arr->size == arr->capacity) {
    arr->capacity *= 2;
    arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    if (!arr->data) {
      printf("Memory allocation failed\n");
      return;
    }
  }
  arr->data[arr->size++] = value;
}

void insert(DynamicArray *arr, size_t index, int value) {
  if (index > arr->size) {
    printf("Index out of bounds\n");
    return;
  }

  if (arr->size == arr->capacity) {
    arr->capacity *= 2;
    arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    if (!arr->data) {
      printf("Memory allocation failed\n");
      return;
    }
  }

  for (size_t i = arr->size; i > index; i--) {
    arr->data[i] = arr->data[i - 1]; // Shift elements to the right
  }
  
  arr->data[index] = value;
  arr->size++;
}

void delete(DynamicArray *arr, size_t index) {
  if (index >= arr->size) {
    printf("Index out of bounds\n");
    return;
  }

  for (size_t i = index; i < arr->size - 1; i++) {
    arr->data[i] = arr->data[i + 1]; // Shift elements to the left
  }

  arr->size--;
}

int get(DynamicArray *arr, size_t index) {
  if (index >= arr->size) {
    printf("Index out of bounds\n");
    return -1;
  }

  return arr->data[index];
}

void free_array(DynamicArray *arr) {
  free(arr->data);
  free(arr);
}

void print_array(DynamicArray *arr) {
  printf("[ ");
  for (size_t i = 0; i < arr->size; i++) {
    printf("%d ", arr->data[i]);
  }
  printf(" ]\n");
}
