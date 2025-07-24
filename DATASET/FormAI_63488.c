//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUMBERS 10

int numbers[MAX_NUMBERS] = {0};
int max_sum = 0;

void* calculate_sum(void* arg) {
    int start = *(int*) arg;
    int sum = 0;
    for(int i = start; i < MAX_NUMBERS; i += 2) {
        sum += numbers[i];
    }
    if(sum > max_sum) {
        max_sum = sum;
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t threads[2];
    int thread_args[2] = {0, 1};

    for(int i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % 100;
    }

    printf("Numbers: ");
    for(int i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    pthread_create(&threads[0], NULL, calculate_sum, &thread_args[0]);
    pthread_create(&threads[1], NULL, calculate_sum, &thread_args[1]);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    printf("Max sum: %d\n", max_sum);

    return 0;
}