//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(void *arg) {
    printf("Thread running...\n");
    int *num = (int *) arg;

    if (*num < 0) {
        printf("ERROR: Invalid number passed to thread.\n");
        pthread_exit(NULL);
    }

    printf("Calculating square of %d...\n", *num);
    int result = (*num) * (*num);
    printf("Square of %d is %d\n", *num, result);

    pthread_exit(NULL);
}

int main() {
    int num1 = 7, num2 = -2;

    printf("Creating thread 1...\n");
    pthread_t tid1;
    if (pthread_create(&tid1, NULL, thread_func, &num1) != 0) {
        perror("pthread_create error");
        exit(EXIT_FAILURE);
    }

    printf("Creating thread 2...\n");
    pthread_t tid2;
    if (pthread_create(&tid2, NULL, thread_func, &num2) != 0) {
        perror("pthread_create error");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for thread 1 to finish...\n");
    if (pthread_join(tid1, NULL) != 0) {
        perror("pthread_join error");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for thread 2 to finish...\n");
    if (pthread_join(tid2, NULL) != 0) {
        perror("pthread_join error");
        exit(EXIT_FAILURE);
    }

    printf("Program exiting normally.\n");
    return 0;
}