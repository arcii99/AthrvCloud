//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;

void *calculate_sum(void *arg) {
    int *arr = arg;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    pthread_exit(NULL);
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, calculate_sum, arr);
    pthread_join(tid, NULL);

    printf("The sum of the array is %d\n", sum);

    pthread_attr_destroy(&attr);
    return 0;
}