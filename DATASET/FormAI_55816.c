//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

pthread_mutex_t mutex;
int log_count = 0;

void* log_analyzer(void* arg) {
    int thread_id = *(int*)arg;
    int local_count = 0;

    FILE *log_file;
    char ch;

    // Open log file
    log_file = fopen("server.log", "r");

    // Lock mutex while reading from file
    pthread_mutex_lock(&mutex);

    // Read character by character until end of file
    while ((ch = fgetc(log_file)) != EOF) {
        if (ch == '\n') {
            local_count++;
        }
    }

    // Update global log count
    log_count += local_count;

    // Unlock mutex
    pthread_mutex_unlock(&mutex);

    // Close log file
    fclose(log_file);

    printf("Thread %d analyzed %d logs\n", thread_id, local_count);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, &log_analyzer, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total logs analyzed: %d\n", log_count);

    // Clean up
    pthread_mutex_destroy(&mutex);

    return 0;
}