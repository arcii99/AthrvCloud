//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_METADATA_SIZE 50

pthread_mutex_t metadata_mutex = PTHREAD_MUTEX_INITIALIZER;
char metadata[MAX_METADATA_SIZE];

void *extract_metadata(void *filename) {
    char *file = (char *) filename;
    // Simulating metadata extraction by sleeping for random number of seconds
    int sleep_time = rand() % 5 + 1;
    printf("Thread for %s started\n", file);
    printf("Extracting metadata for %s...\n", file);
    printf("Estimated extraction time: %d second(s)\n", sleep_time);
    sleep(sleep_time);
    char extracted_data[MAX_METADATA_SIZE];
    sprintf(extracted_data, "Metadata for %s: Author - John Doe; Size - 10MB", file);
    pthread_mutex_lock(&metadata_mutex);
    if (strlen(metadata) + strlen(extracted_data) < MAX_METADATA_SIZE) {
        strcat(metadata, extracted_data);
    }
    pthread_mutex_unlock(&metadata_mutex);
    printf("Thread for %s finished\n", file);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));  // Start random number generator
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Extract metadata for each file given as input
    int i;
    for (i = 1; i < argc; i++) {
        pthread_create(&threads[thread_count++], NULL, extract_metadata, (void *) argv[i]);
        if (thread_count == MAX_THREADS) {
            // Wait for all threads to finish before starting new batch
            int j;
            for (j = 0; j < thread_count; j++) {
                pthread_join(threads[j], NULL);
            }
            thread_count = 0;  // Reset thread count
        }
    }

    // Wait for remaining threads to finish
    int j;
    for (j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("\nExtracted metadata:\n%s\n", metadata);
    pthread_exit(NULL);
}