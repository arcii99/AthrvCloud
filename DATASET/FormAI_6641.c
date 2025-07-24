//FormAI DATASET v1.0 Category: Educational ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 100

int array[ARRAY_SIZE];
int sum = 0;

void *sum_array(void *arg) {
    int i;
    int thread_sum = 0;
    int thread_num = *(int *) arg;
    int start_index = thread_num * (ARRAY_SIZE / 2);

    for (i = start_index; i < start_index + (ARRAY_SIZE/2); i++) {
        thread_sum += array[i];
    }
    printf("Thread %d sum: %d\n", thread_num, thread_sum);
    sum += thread_sum;

    return NULL;
}

int main() {
    pthread_t t1, t2;
    int thread1_num = 1;
    int thread2_num = 2;

    // fill array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }

    // create threads
    pthread_create(&t1, NULL, sum_array, &thread1_num);
    pthread_create(&t2, NULL, sum_array, &thread2_num);

    // wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // print result
    printf("Total sum: %d\n", sum);

    return 0;
}