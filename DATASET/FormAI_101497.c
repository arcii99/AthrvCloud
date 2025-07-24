//FormAI DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LENGTH 500

struct log_entry {
    char *timestamp;
    char *message;
};

struct log {
    struct log_entry entries[MAX_LOG_ENTRIES];
    int size;
    pthread_mutex_t lock;
};

// Adds an entry to the log
void add_entry(struct log *log, char *timestamp, char *message) {
    pthread_mutex_lock(&log->lock);

    struct log_entry new_entry = {timestamp, message};

    // Only add the entry if there's room in the log
    if (log->size < MAX_LOG_ENTRIES) {
        log->entries[log->size] = new_entry;
        log->size++;
    }

    pthread_mutex_unlock(&log->lock);
}

// Searches the log for entries that contain the given message
void search_log(struct log *log, char *search_term) {
    pthread_mutex_lock(&log->lock);

    for (int i = 0; i < log->size; i++) {
        if (strstr(log->entries[i].message, search_term) != NULL) {
            printf("%s %s\n", log->entries[i].timestamp, log->entries[i].message);
        }
    }

    pthread_mutex_unlock(&log->lock);
}

// Deletes the log
void delete_log(struct log *log) {
    pthread_mutex_lock(&log->lock);

    for (int i = 0; i < log->size; i++) {
        free(log->entries[i].timestamp);
        free(log->entries[i].message);
    }

    log->size = 0;

    pthread_mutex_unlock(&log->lock);
}

// Thread function that repeatedly adds an entry to the log
void *add_entry_thread(void *arg) {
    struct log *log = (struct log *)arg;

    for (int i = 0; i < 10; i++) {
        char *timestamp = "2022-01-01 12:00:00";
        char *message = "New log entry added.";

        add_entry(log, timestamp, message);

        usleep(100000); // Wait 0.1 seconds between entries
    }

    pthread_exit(NULL);
}

int main() {
    struct log log = {0};
    pthread_mutex_init(&log.lock, NULL);

    // Start the thread that adds entries to the log
    pthread_t add_thread;
    pthread_create(&add_thread, NULL, add_entry_thread, &log);

    // Wait for the thread to finish
    pthread_join(add_thread, NULL);

    // Search for entries with the word "New"
    search_log(&log, "New");

    // Delete the log
    delete_log(&log);

    return 0;
}