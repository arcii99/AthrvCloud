//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: immersive
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10

void* printThreadNumber(void* threadNumber) {
  int num = *(int*) threadNumber;
  printf("Hello from thread number %d\n", num);
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  int threadNums[NUM_THREADS];
  
  for (int i = 0; i < NUM_THREADS; i++) {
    threadNums[i] = i;
    int rc = pthread_create(&threads[i], NULL, printThreadNumber, (void*) &threadNums[i]);
    
    if (rc) {
      printf("ERROR: return code from pthread_create() is %d\n", rc);
      return -1;
    }
  }
  
  pthread_exit(NULL);
}