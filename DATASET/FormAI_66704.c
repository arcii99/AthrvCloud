//FormAI DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ENTRIES 10
#define MAX_MESSAGE_LENGTH 50

typedef struct {
    char message[MAX_MESSAGE_LENGTH];
    char date[11];
} diary_entry_t;

void *add_entry(void *arg);
void *view_entries(void *arg);

diary_entry_t diary[MAX_ENTRIES];
int num_entries = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    pthread_t add_thread, view_thread;

    // Create two threads: one to add entries and one to view entries
    pthread_create(&add_thread, NULL, add_entry, NULL);
    pthread_create(&view_thread, NULL, view_entries, NULL);

    // Wait for both threads to finish
    pthread_join(add_thread, NULL);
    pthread_join(view_thread, NULL);

    return 0;
}

void *add_entry(void *arg) {
    char message[MAX_MESSAGE_LENGTH];
    char date[11];
    diary_entry_t entry;

    while (1) {
        // Get the message from the user
        printf("Enter a message (or 'quit' to exit): ");
        fgets(message, MAX_MESSAGE_LENGTH, stdin);
        if (strcmp(message, "quit\n") == 0) {
            break;
        }

        // Add the message to the diary entry
        printf("Enter a date (MM/DD/YYYY): ");
        fgets(date, 11, stdin);
        strncpy(entry.message, message, MAX_MESSAGE_LENGTH);
        strncpy(entry.date, date, 11);

        // Add the entry to the diary (with thread safety)
        pthread_mutex_lock(&mutex); // Lock the mutex to prevent race conditions
        if (num_entries < MAX_ENTRIES) { // Make sure there is room in the diary
            diary[num_entries++] = entry;
        } else {
            printf("Diary is full!\n");
        }
        pthread_mutex_unlock(&mutex); // Unlock the mutex when finished
    }

    return NULL;
}

void *view_entries(void *arg) {
    while (1) {
        // Display all the entries in the diary (with thread safety)
        pthread_mutex_lock(&mutex); // Lock the mutex to prevent race conditions
        if (num_entries > 0) { // Only display entries if there are any
            printf("\nDiary Entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("%s: %s", diary[i].date, diary[i].message);
            }
        } else {
            printf("\nNo entries yet.\n");
        }
        pthread_mutex_unlock(&mutex); // Unlock the mutex when finished

        // Wait for a few seconds before displaying the entries again
        sleep(3);
    }

    return NULL;
}