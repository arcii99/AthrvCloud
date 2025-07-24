//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: synchronous
#include <pthread.h>
#include <stdio.h>

// Struct for a thread's argument
typedef struct {
    int thread_num;
    int start;
    int end;
} ThreadArgs;

// Thread function
void *sum_array(void *arg) {
    ThreadArgs *args = (ThreadArgs *) arg;
    int sum = 0;
    // Sum array elements within thread's range
    for (int i = args->start; i < args->end; i++) {
        sum += i;
    }
    printf("Thread %d sum: %d\n", args->thread_num, sum);
    // Return sum as thread's result
    pthread_exit((void *) sum);
}

int main() {
    int num_threads = 4;
    int array_size = 100;
    int thread_args_size = array_size / num_threads;
    int sum = 0;
    pthread_t threads[num_threads];
    ThreadArgs thread_args[num_threads];

    // Create threads and pass thread arguments
    for (int i = 0; i < num_threads; i++) {
        thread_args[i].thread_num = i;
        thread_args[i].start = i * thread_args_size;
        // Last thread covers all remaining elements
        thread_args[i].end = (i == num_threads - 1) ? array_size : (i + 1) * thread_args_size;
        pthread_create(&threads[i], NULL, sum_array, (void *) &thread_args[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < num_threads; i++) {
        void *thread_result;
        pthread_join(threads[i], &thread_result);
        sum += (int) thread_result;
    }

    printf("Total sum: %d\n", sum);
    return 0;
}