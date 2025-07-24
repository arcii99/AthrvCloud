//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_fun(void *arg) {
    int *tid = (int *)arg;
    int num = *tid;
    sleep(1);
    printf("Hello from thread_%d\n", num);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread[5];
    int i, tid[5];
    for (i = 0; i < 5; i++) {
        tid[i] = i + 1;
        printf("Creating thread_%d\n", tid[i]);
        int ret = pthread_create(&thread[i], NULL, thread_fun, &tid[i]);
        if (ret) {
            printf("Thread_%d could not be created\n", tid[i]);
            exit(1);
        }
    }

    for (i = 0; i < 5; i++) {
        pthread_join(thread[i], NULL);
        printf("Thread_%d has finished executing\n", tid[i]);
    }

    printf("All threads have exited successfully\n");
    pthread_exit(NULL);
}