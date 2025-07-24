//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: enthusiastic
// Welcome to the exciting world of multithreading in C!
// Let's start by creating our own threading library implementation.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a thread structure to hold the function and arguments for a thread.
typedef struct {
    void *(*start_routine)(void *);
    void *arg;
} thread_t;

// Define our own thread creation function that uses the pthread library.
void thread_create(thread_t *thread, void *(*start_routine)(void *), void *arg) {
    thread->start_routine = start_routine;
    thread->arg = arg;
    pthread_t tid;
    pthread_create(&tid, NULL, start_routine, arg);
}

// Define our own thread joining function that uses the pthread library.
void thread_join(thread_t *thread) {
    pthread_join(pthread_self(), NULL);
}

// Let's define a simple example function that prints out numbers.
void *print_numbers(void *arg) {
    int *num_ptr = (int *) arg;
    for (int i = 1; i <= *num_ptr; i++) {
        printf("%d ", i);
    }
    printf("\n");
    return NULL;
}

// Now let's use our own threading library to create and join threads.
int main() {
    int num1 = 5;
    int num2 = 10;
    thread_t thread1, thread2;
    
    printf("Let's start our threads...\n");
    thread_create(&thread1, print_numbers, &num1);
    thread_create(&thread2, print_numbers, &num2);
    
    printf("Waiting for threads to finish...\n");
    thread_join(&thread1);
    thread_join(&thread2);
    
    printf("All threads finished!\n");
    
    return 0;
}