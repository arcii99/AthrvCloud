//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define SIZE 1000000

// Asynchronous bubble sort function
void *async_bubble_sort(void *array_ptr) {
  int *array = (int *)array_ptr;
  int i, j;
  for (i = 0; i < SIZE - 1; i++) {
    for (j = 0; j < SIZE - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  return NULL;
}

int main() {
  srand((unsigned int)time(NULL));
  
  int array[SIZE];
  int i;
  for (i = 0; i < SIZE; i++) {
    array[i] = rand() % 1000;
  }
  
  pthread_t tid;
  pthread_create(&tid, NULL, async_bubble_sort, array);
  
  // Do some other work here...
  
  pthread_join(tid, NULL);
  
  printf("Sorted array:\n");
  for (i = 0; i < SIZE; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  
  return 0;
}