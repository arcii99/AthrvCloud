//FormAI DATASET v1.0 Category: Data mining ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_DATA 100

// Struct representing a data record
typedef struct {
    char id[10];
    float value1;
    float value2;
} DataRecord;

// Struct representing a processed data record
typedef struct {
    char id[10];
    float result;
} ProcessedData;

// Global arrays for storing raw and processed data
DataRecord raw_data[MAX_DATA];
ProcessedData processed_data[MAX_DATA];

// Global variables for tracking progress
int data_count = 0;
int processed_count = 0;

// Function for simulating data generation
void generate_data() {
    for (int i = 1; i <= MAX_DATA; i++) {
        DataRecord record;
        sprintf(record.id, "ID%03d", i);
        record.value1 = (float) (rand() % 100);
        record.value2 = (float) (rand() % 100);
        raw_data[i-1] = record;
        data_count++;
    }
    printf("Generated %d data records.\n", data_count);
}

// Function for processing data records
void* process_data(void* arg) {
    int thread_id = *(int*) arg;
    int start = (MAX_DATA/MAX_THREADS) * thread_id;
    int end = (MAX_DATA/MAX_THREADS) * (thread_id + 1);
    if (thread_id == MAX_THREADS - 1) {
        end = MAX_DATA;
    }
    for (int i = start; i < end; i++) {
        ProcessedData result;
        strcpy(result.id, raw_data[i].id);
        result.result = raw_data[i].value1 + raw_data[i].value2;
        processed_data[i] = result;
        processed_count++;
    }
    printf("Thread %d processed %d data records.\n", thread_id, end-start);
    pthread_exit(NULL);
}

// Function for displaying results
void display_results() {
    printf("Processed %d data records.\n", processed_count);
    printf("ID\tResult\n");
    for (int i = 0; i < MAX_DATA; i++) {
        if (processed_data[i].result != 0) {
            printf("%s\t%.2f\n", processed_data[i].id, processed_data[i].result);
        }
    }
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    srand(time(NULL));

    // Generate data
    generate_data();

    // Create threads
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, process_data, &thread_ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display results
    display_results();

    return 0;
}