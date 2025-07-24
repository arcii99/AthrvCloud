//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int sum = 0;

void* add_numbers(void* arg) {
    int* arr = (int*) arg;
    int local_sum = 0;

    for(int i=0; i<5; i++) {
        local_sum += arr[i];
    }

    sum += local_sum;
    pthread_exit(NULL);
}

int main() {
    srand(time(0));

    int rand_nums[50];
    for(int i=0; i<50; i++) {
        rand_nums[i] = rand() % 100 + 1;
    }

    pthread_t threads[10];
    int thread_args[10][5] = {{0}};
    int t;

    for(t=0; t<10; t++) {
        int* p = &rand_nums[t*5];
        thread_args[t][0] = *p;
        thread_args[t][1] = *(p+1);
        thread_args[t][2] = *(p+2);
        thread_args[t][3] = *(p+3);
        thread_args[t][4] = *(p+4);

        pthread_create(&threads[t], NULL, add_numbers, &thread_args[t]);
    }

    for(t=0; t<10; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Total Sum: %d", sum);

    return 0;
}