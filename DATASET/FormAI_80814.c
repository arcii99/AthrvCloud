//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: future-proof
#include <stdio.h>
#include <pthread.h>

void* thread_1(void* arg) {
    int* num = (int*) arg;
    printf("Thread 1 with argument %d is running\n", *num);
    pthread_exit(NULL);
}

void* thread_2(void* arg) {
    int* num = (int*) arg;
    printf("Thread 2 with argument %d is running\n", *num);
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    int arg1 = 1, arg2 = 2;

    // create thread 1
    if(pthread_create(&t1, NULL, thread_1, &arg1) != 0) {
        perror("Thread 1 creation failed\n");
        return 1;
    }

    // create thread 2
    if(pthread_create(&t2, NULL, thread_2, &arg2) != 0) {
        perror("Thread 2 creation failed\n");
        return 1;
    }

    // wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}