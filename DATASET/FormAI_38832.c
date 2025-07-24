//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define THREADS_NUM 5
#define MAX_RANDOM_NUM 50
#define MIN_RANDOM_NUM -50

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int numbers_sum = 0;
bool done = false;

int get_random_num() {
    return rand() % MAX_RANDOM_NUM + MIN_RANDOM_NUM;
}

void *compute_sum(void *thread_id) {
    int id = *(int *) thread_id;
    printf("Thread %d started...\n", id);
    int sum = 0;
    while(!done) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        if(numbers_sum % THREADS_NUM == id) {
            sum += numbers_sum;
            printf("Thread %d processed %d\n", id, numbers_sum);
        }
        pthread_mutex_unlock(&mutex);
    }
    printf("Thread %d finished with sum %d\n", id, sum);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    pthread_t threads[THREADS_NUM];
    int threads_id[THREADS_NUM];
    for(int i = 0; i < THREADS_NUM; i++) {
        threads_id[i] = i;
        pthread_create(&threads[i], NULL, compute_sum, (void *) &threads_id[i]);
    }

    int numbers_left = 100;
    while(numbers_left > 0) {
        pthread_mutex_lock(&mutex);
        numbers_sum = get_random_num();
        printf("Main thread inserted %d\n", numbers_sum);
        numbers_left--;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    done = true;
    pthread_cond_broadcast(&cond);
    for(int i = 0; i < THREADS_NUM; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}