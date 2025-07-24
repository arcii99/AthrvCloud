//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define THREAD_NUM 5

void *print_hello(void *thread_id)
{
  long id = (long)thread_id;
  printf("Thread %ld says hello!\n", id);
  
  pthread_exit(NULL);
}

int main()
{
  pthread_t threads[THREAD_NUM];
  int rc;
  long t;

  for(t=0; t<THREAD_NUM; t++){
    printf("Creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);
     
    if (rc){
      printf("Error: Unable to create thread %d\n", rc);
      return -1;
    }
  }
  
  pthread_exit(NULL);
}