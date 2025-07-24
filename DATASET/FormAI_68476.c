//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 5

void *exploreSpace(void *);

int main() {
  pthread_t threads[MAX_THREADS];

  int i;
  for(i=0; i<MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, exploreSpace, (void *)i);
  }

  for(i=0; i<MAX_THREADS; i++) {
    int *result;
    pthread_join(threads[i], (void **)&result);
    printf("Thread %d finished with result %d\n", i, *result);
  }

  printf("All threads have finished\n");

  return 0;
}

void *exploreSpace(void *threadNum) {
  int num = (int)threadNum;
  printf("Thread %d exploring space\n", num);
  sleep(2);
  printf("Thread %d finished exploring space\n", num);

  int *result = malloc(sizeof(int));
  *result = num * 10;

  pthread_exit(result);
}