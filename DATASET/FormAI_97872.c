//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include <stdio.h>

int main() {
  int arr[5] = {10, 20, 30, 40, 50};
  int *ptr = &arr[2];

  // Print the address of ptr
  printf("Address of ptr: %p\n", &ptr);

  // Print the value of ptr
  printf("Value of ptr: %p\n", ptr);

  // Print the value of *ptr
  printf("Value of *ptr: %d\n", *ptr);

  // Increment the value of ptr by 1
  ptr++;

  // Print the value of ptr after increment
  printf("Value of ptr after increment: %p\n", ptr);

  // Print the value of *ptr after increment
  printf("Value of *ptr after increment: %d\n", *ptr);

  // Decrement the value of ptr by 1
  ptr--;

  // Print the value of ptr after decrement
  printf("Value of ptr after decrement: %p\n", ptr);

  // Print the value of *ptr after decrement
  printf("Value of *ptr after decrement: %d\n", *ptr);

  return 0;
}