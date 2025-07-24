//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg) {
  if (arg == NULL) {
    printf("Thread function arg is NULL\n");
    return NULL;
  }
  
  char* str = (char*)arg;
  printf("Thread function received arg: %s\n", str);
  return NULL;
}

int main() {
  pthread_t thread_id;
  int ret;

  char* arg = "Hello world";

  ret = pthread_create(&thread_id, NULL, thread_function, (void*)arg);
  
  if (ret != 0) {
    printf("ERROR: pthread_create failed: %d\n", ret);
    exit(EXIT_FAILURE);
  }
  
  ret = pthread_join(thread_id, NULL);
  
  if (ret != 0) {
    printf("ERROR: pthread_join failed: %d\n", ret);
    exit(EXIT_FAILURE);
  }
  
  printf("Thread exited successfully\n"); 
  return 0;
}