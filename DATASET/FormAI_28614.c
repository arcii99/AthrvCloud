//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
// Donald Knuth-style implementation of C Threading Library

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
  int id;
  int num;
} thread_args;

void *fibonacci(void *args) {
  thread_args *t = (thread_args *) args;
  int x = 0, y = 1, temp, i;

  for (i = 0; i < t->num; i++) {
    printf("Fibonacci %d-%d: %d\n", t->id, i + 1, x);
    temp = x + y;
    x = y;
    y = temp;
  }

  pthread_exit(NULL);
}

int main() {
  int i, num_threads;

  printf("Enter the number of threads: ");
  scanf("%d", &num_threads);

  pthread_t threads[num_threads];
  thread_args args[num_threads];

  for (i = 0; i < num_threads; i++) {
    args[i].id = i + 1;
    printf("Enter the number of Fibonacci numbers for Thread %d: ", i + 1);
    scanf("%d", &args[i].num);

    pthread_create(&threads[i], NULL, fibonacci, &args[i]);
  }

  for (i = 0; i < num_threads; i++)
    pthread_join(threads[i], NULL);

  return 0;
}