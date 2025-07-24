//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int id;
    char *message;
} thread_args;

void *thread_func(void *arg) {
    thread_args *args = (thread_args *)arg;
    printf("Thread %d: %s\n", args->id, args->message);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    thread_args thread1_args, thread2_args;
    thread1_args.id = 1;
    thread1_args.message = "Hello from thread 1!";
    thread2_args.id = 2;
    thread2_args.message = "Hello from thread 2!";
    pthread_create(&thread1, NULL, thread_func, (void *)&thread1_args);
    pthread_create(&thread2, NULL, thread_func, (void *)&thread2_args);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}