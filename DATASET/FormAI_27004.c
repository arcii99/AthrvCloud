//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: real-life
#include <stdio.h>

#define SIZE 1000

int main() {
  int arr[SIZE];

  // generate random numbers
  for(int i = 0; i < SIZE; i++)
    arr[i] = rand() % 100;

  // check for duplicates
  for(int i = 0; i < SIZE; i++) {
    for(int j = i+1; j < SIZE; j++) {
      if(arr[i] == arr[j]) {
        printf("Duplicate found: %d\n", arr[i]);
        break;
      }
    }
  }

  return 0;
}