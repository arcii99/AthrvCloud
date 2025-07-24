//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// This program demonstrates a threading library implementation in C.

// Define a structure that holds thread information
typedef struct _threadinfo {
  int id; // the ID for the thread
  int count; // the number of times the thread will run
} threadinfo;

// Define a function that each thread will run
void *run(void *tinfo) {
  threadinfo *info = (threadinfo *) tinfo;
  int id = info->id;
  int count = info->count;
  int i; // counter variable for loop

  for(i = 0; i < count; i++) {
    printf("Thread %d running: %d times\n", id, i+1);
    sleep(1); // wait one second before running again
  }

  printf("Thread %d finished\n", id);
  pthread_exit(NULL);
}

// Main function that creates threads and runs them
int main() {
  int num_threads = 5; // number of threads to create
  pthread_t threads[num_threads]; // array of threads
  threadinfo tinfo[num_threads]; // array of threadinfo structs
  int i; // counter variable for loop

  // Create threads
  for(i = 0; i < num_threads; i++) {
    tinfo[i].id = i+1;
    tinfo[i].count = (i+1) * 3; // set count to 3 times the ID of the thread
    if(pthread_create(&threads[i], NULL, run, &tinfo[i])) {
      fprintf(stderr, "Error creating thread %d\n", i);
      exit(1);
    }
  }

  // Wait for threads to finish
  for(i = 0; i < num_threads; i++) {
    if(pthread_join(threads[i], NULL)) {
      fprintf(stderr, "Error joining thread %d\n", i);
      exit(1);
    }
  }

  printf("All threads finished\n");
  return 0;
}