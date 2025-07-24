//FormAI DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *addition(void *arg); // function for addition thread
void *subtraction(void *arg); // function for subtraction thread

int main() {
  pthread_t add_thread, sub_thread; // declare thread variables
  int num1 = 10, num2 = 5;

  // create threads and pass arguments to the function
  if(pthread_create(&add_thread, NULL, addition, (void *)&num1) != 0) {
    perror("Error creating addition thread");
    exit(1);
  }

  if(pthread_create(&sub_thread, NULL, subtraction, (void *)&num2) != 0) {
    perror("Error creating subtraction thread");
    exit(1);
  }

  // wait for threads to finish execution
  if(pthread_join(add_thread, NULL) != 0) {
    perror("Error joining addition thread");
    exit(1);
  }

  if(pthread_join(sub_thread, NULL) != 0) {
    perror("Error joining subtraction thread");
    exit(1);
  }

  printf("Threads finished execution\n");
  return 0;
}

void *addition(void *arg) {
  int num = *(int *)arg;
  int result = 0;
  for(int i=1; i<=num; i++) {
    result += i;
  }
  printf("Addition result: %d\n", result);
  pthread_exit(NULL); // exit thread
}

void *subtraction(void *arg) {
  int num = *(int *)arg;
  int result = 20;
  for(int i=1; i<=num; i++) {
    result -= i;
  }
  printf("Subtraction result: %d\n", result);
  pthread_exit(NULL); // exit thread
}