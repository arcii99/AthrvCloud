//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Global variable for thread synchronization
pthread_mutex_t mutex;

void *thread_function(void *arg) {
  int n = *((int*)arg);
  
  //Locking the mutex
  pthread_mutex_lock(&mutex);
  
  printf("Thread %d started.\n", n);
  
  printf("Thread %d is running.\n", n);
  
  printf("Thread %d finished.\n", n);
  
  //Unlocking the mutex
  pthread_mutex_unlock(&mutex);
  
  return NULL;
}

int main() {
  //initializing the mutex
  if (pthread_mutex_init(&mutex, NULL) != 0) {
    printf("Mutex initialization failed.\n");
    return 1;
  }
  
  pthread_t thread1, thread2, thread3, thread4;
  int n1 = 1, n2 = 2, n3 = 3, n4 = 4;
  
  printf("Creating threads...\n");
  
  //Creating threads
  pthread_create(&thread1, NULL, &thread_function, &n1);
  pthread_create(&thread2, NULL, &thread_function, &n2);
  pthread_create(&thread3, NULL, &thread_function, &n3);
  pthread_create(&thread4, NULL, &thread_function, &n4);
  
  printf("Threads created.\n");
  
  //Waiting for threads to finish
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_join(thread3, NULL);
  pthread_join(thread4, NULL);

  //Destroying the mutex
  pthread_mutex_destroy(&mutex);
  
  return 0;
}