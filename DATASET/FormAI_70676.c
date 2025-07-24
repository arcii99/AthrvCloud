//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define function pointer
typedef void* (*thread_func)(void*);

// Define thread data structure
typedef struct {
  pthread_t id;
  thread_func func;
  void* arg;
} Thread;

// Function to initialize a thread
Thread* init_thread(thread_func func, void* arg) {
  Thread* thread = (Thread*) malloc(sizeof(Thread));
  thread->func = func;
  thread->arg = arg;
  pthread_create(&thread->id, NULL, thread->func, thread->arg);
  return thread;
}

// Function to join a thread
void join_thread(Thread* thread) {
  pthread_join(thread->id, NULL);
  free(thread);
}

// Function to print a message
void* print_message(void* msg) {
  char* message = (char*) msg;
  printf("%s\n", message);
  return NULL;
}

int main() {
  // Initialize threads
  Thread* thread1 = init_thread(print_message, "Hello from thread 1!");
  Thread* thread2 = init_thread(print_message, "Hello from thread 2!");

  // Join threads
  join_thread(thread1);
  join_thread(thread2);

  return 0;
}