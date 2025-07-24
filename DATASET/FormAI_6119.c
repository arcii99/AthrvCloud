//FormAI DATASET v1.0 Category: Scientific ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1_func(void *arg);
void *thread2_func(void *arg);

int main() {
  pthread_t thread1, thread2;

  int *input1 = malloc(sizeof(int));
  int *input2 = malloc(sizeof(int));
  
  printf("Enter the first integer value: ");
  scanf("%d", input1);
  printf("Enter the second integer value: ");
  scanf("%d", input2);

  pthread_create(&thread1, NULL, thread1_func, (void *)input1);
  pthread_create(&thread2, NULL, thread2_func, (void *)input2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  free(input1);
  free(input2);

  printf("\nProgram execution complete.\n");
  return 0;
}

void *thread1_func(void *arg) {
  int x = *((int *) arg);
  printf("\nThread 1: Square of %d = %d", x, x*x);
  return NULL;
}

void *thread2_func(void *arg) {
  int y = *((int *) arg);
  printf("\nThread 2: Cube of %d = %d\n", y, y*y*y);
  return NULL;
}