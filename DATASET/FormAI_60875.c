//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: immersive
#include <stdio.h>
#include <pthread.h>

void *thread_func(void *);

int main() {
    pthread_t thread;
    int value = 10;

    pthread_create(&thread, NULL, thread_func, &value);

    printf("Main thread waiting for child thread to complete...\n");

    pthread_join(thread, NULL);

    printf("Child thread has completed\n");

    return 0;
}

void *thread_func(void *arg) {
    int *p_value = (int*) arg;
    printf("Child thread start\n");
    printf("Value passed to the child thread is: %d\n", *p_value);
    printf("Child thread end\n");
    pthread_exit(0);
}