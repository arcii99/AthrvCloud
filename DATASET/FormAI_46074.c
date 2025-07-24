//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

#define WORK_LOAD_TIME_MIN 1000000 // Minimum work load time in microseconds
#define WORK_LOAD_TIME_MAX 2000000 // Maximum work load time in microseconds
#define NUM_THREADS 4 // Number of worker threads to be spawned

// Struct to hold thread-specific data
typedef struct thread_data {
    int id; // Thread ID
    int *work_load; // Pointer to shared work load data
    bool *work_done; // Pointer to shared work done data
    pthread_mutex_t *lock; // Pointer to shared mutex lock
} thread_data;

// Function to simulate a performance-critical task
void perform_work(int id) {
    int work_load_time = (rand() % (WORK_LOAD_TIME_MAX - WORK_LOAD_TIME_MIN + 1)) + WORK_LOAD_TIME_MIN; // Generate random work load time in microseconds
    printf("Worker %d is performing work for %d microseconds.\n", id, work_load_time);
    usleep(work_load_time);
}

// Function to be executed by each worker thread
void* worker(void *arg) {
    thread_data *data = (thread_data*) arg;
    while (true) {
        // Check if all work is done
        if (*data->work_done) {
            break;
        }
        // Wait for mutex lock
        pthread_mutex_lock(data->lock);
        // Check if there is work to be done
        if (*data->work_load > 0) {
            // Perform work
            perform_work(data->id);
            // Decrement shared work load
            (*data->work_load)--;
        }
        // Release mutex lock
        pthread_mutex_unlock(data->lock);
    }
    printf("Worker %d is done.\n", data->id);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int work_load = 10; // Set initial work load
    bool work_done = false; // Set initial work done status
    pthread_t threads[NUM_THREADS]; // Thread IDs
    thread_data thread_data_arr[NUM_THREADS]; // Thread-specific data
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // Mutex lock to prevent race conditions
    // Spawn worker threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_arr[i].id = i;
        thread_data_arr[i].work_load = &work_load;
        thread_data_arr[i].work_done = &work_done;
        thread_data_arr[i].lock = &lock;
        pthread_create(&threads[i], NULL, worker, (void*) &thread_data_arr[i]);
    }
    // Wait for user input to signal end of work
    printf("Press any key to signal end of work.\n");
    getchar();
    // Update shared work done status
    pthread_mutex_lock(&lock);
    work_done = true;
    pthread_mutex_unlock(&lock);
    // Wait for worker threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All work is done.\n");
    return 0;
}