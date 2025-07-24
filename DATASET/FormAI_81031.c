//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of records that can be stored
#define MAX_RECORDS 100

// Define the maximum length of a name or phone number
#define MAX_NAME_LEN 30
#define MAX_PHONE_LEN 20

// Define the number of threads
#define NUM_THREADS 4

// Define a record struct
typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Record;

// Define a Index struct
typedef struct {
    char key[MAX_NAME_LEN];
    int index;
} Index;

// Define a global array of records
Record records[MAX_RECORDS];

// Define a global array of indexes
Index indexes[MAX_RECORDS];

// Define the length of the records array
int record_count = 0;

// Define the length of the indexes array
int index_count = 0;

// Define a mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define a thread function to add an index
void *add_index(void *arg) {
    // Cast the argument back to an index pointer
    Index *index = (Index *) arg;

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Add the index to the indexes array
    indexes[index_count] = *index;
    index_count++;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Exit the thread
    pthread_exit(NULL);
}

// Define a function to add a record
void add_record(char *name, char *phone) {
    // Create a new record and set its values
    Record record;

    // Copy the name and phone number into the record struct
    strncpy(record.name, name, MAX_NAME_LEN);
    strncpy(record.phone, phone, MAX_PHONE_LEN);

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Add the record to the records array
    records[record_count] = record;
    record_count++;

    // Create a new index and set its values
    Index index;

    // Copy the name into the index struct
    strncpy(index.key, name, MAX_NAME_LEN);

    // Set the index value to the current index count
    index.index = record_count - 1;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Create a thread to add the index
    pthread_t thread;
    pthread_create(&thread, NULL, add_index, (void *) &index);

    // Join the thread
    pthread_join(thread, NULL);
}

// Define a function to search for a record
void search_record(char *name) {
    // Create a boolean flag to indicate whether the record was found
    bool found = false;

    // Iterate over the indexes array
    for (int i = 0; i < index_count; i++) {
        // Check if the key matches the search term
        if (strcmp(indexes[i].key, name) == 0) {
            // Retrieve the record from the records array
            Record record = records[indexes[i].index];

            // Print the record information
            printf("Name: %s\nPhone: %s\n", record.name, record.phone);

            // Set the flag to true
            found = true;
            break;
        }
    }

    // Check if the record was not found
    if (!found) {
        printf("Record not found.\n");
    }
}

// Define the main function
int main() {
    // Add some records
    add_record("John Doe", "555-1234");
    add_record("Jane Smith", "555-5678");
    add_record("Bob Johnson", "555-2468");

    // Search for a record
    search_record("Jane Smith");

    // Exit the program
    return 0;
}