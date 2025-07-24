//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_THREADS 5
#define MAX_PRIMES 100

typedef struct {
    int thread_id;
    int num_threads;
    int start_number;
    int end_number;
} thread_args;

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

void* find_primes(void* args) {
    thread_args* t_args = (thread_args*) args;
    int thread_id = t_args->thread_id;
    int num_threads = t_args->num_threads;
    int start_number = t_args->start_number;
    int end_number = t_args->end_number;

    printf("Thread %d started...\n", thread_id);

    bool primes[MAX_PRIMES];
    int result[MAX_PRIMES];
    int count = 0;

    for (int i = 0; i < MAX_PRIMES; i++) {
        primes[i] = true;
    }

    for (int i = 2; i <= sqrt(end_number); i++) {
        if (is_prime(i)) {
            for (int j = start_number; j <= end_number; j++) {
                if (j % i == 0 && j != i) {
                    primes[j-start_number] = false;
                }
            }
        }
    }

    for (int i = start_number; i <= end_number; i++) {
        if (primes[i-start_number]) {
            result[count] = i;
            count++;
        }
    }

    printf("Thread %d found %d primes.\n", thread_id, count);

    pthread_exit((void*) result);
}

int main() {
    srand(time(NULL)); 

    int num_threads = rand() % MAX_THREADS + 1;
    int start_number = rand() % 1000 + 1;
    int end_number = start_number + rand() % 1000 + 1;
    int range_size = (end_number - start_number) / num_threads;

    printf("Number of threads: %d\n", num_threads);
    printf("Start number: %d\n", start_number);
    printf("End number: %d\n", end_number);

    pthread_t threads[num_threads];
    thread_args thread_args_array[num_threads];

    for (int i = 0; i < num_threads; i++) {
        thread_args_array[i].thread_id = i;
        thread_args_array[i].num_threads = num_threads;
        thread_args_array[i].start_number = start_number + i * range_size;
        thread_args_array[i].end_number = i == num_threads-1 ? end_number : start_number + (i+1) * range_size - 1;

        int rc = pthread_create(&threads[i], NULL, find_primes, (void*)&thread_args_array[i]);

        if (rc) {
            printf("Error: pthread_create failed. Return code: %d\n", rc);
            exit(-1);
        }
    }

    int all_results[MAX_THREADS][MAX_PRIMES];
    int all_counts[MAX_THREADS];
    int total_count = 0;

    for (int i = 0; i < num_threads; i++) {
        void* result;
        int rc = pthread_join(threads[i], &result);

        if (rc) {
            printf("Error: pthread_join failed. Return code: %d\n", rc);
            exit(-1);
        }

        int count = 0;
        int* thread_result = (int*) result;

        for (int j = 0; j < MAX_PRIMES; j++) {
            if (thread_result[j] > 0) {
                all_results[i][count] = thread_result[j];
                count++;
            }
        }

        all_counts[i] = count;
        total_count += count;
    }

    int all_primes[total_count];
    int count = 0;

    for (int i = 0; i < num_threads; i++) {
        for (int j = 0; j < all_counts[i]; j++) {
            all_primes[count] = all_results[i][j];
            count++;
        }
    }

    printf("Found %d primes:\n", total_count);

    for (int i = 0; i < total_count; i++) {
        printf("%d ", all_primes[i]);
    }

    printf("\n");

    pthread_exit(NULL);
}