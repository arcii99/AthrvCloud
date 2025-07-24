//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_ENTRIES 100000 // Maximum number of entries in the database.
#define MAX_THREADS 8 // Maximum number of threads that can be used.

pthread_rwlock_t db_lock; // Read-write lock to protect database.
int num_entries = 0; // Number of entries in the database.
int db[MAX_ENTRIES]; // The database.

// Add a new entry to the database.
void add_entry(int entry) {
    pthread_rwlock_wrlock(&db_lock);
    db[num_entries++] = entry;
    pthread_rwlock_unlock(&db_lock);
}

// Remove an entry from the database.
void remove_entry(int index) {
    pthread_rwlock_wrlock(&db_lock);
    memmove(&db[index], &db[index+1], (num_entries-index-1)*sizeof(int));
    num_entries--;
    pthread_rwlock_unlock(&db_lock);
}

// Search the database for an entry.
int find_entry(int entry) {
    pthread_rwlock_rdlock(&db_lock);
    for (int i = 0; i < num_entries; i++) {
        if (db[i] == entry) {
            pthread_rwlock_unlock(&db_lock);
            return i;
        }
    }
    pthread_rwlock_unlock(&db_lock);
    return -1;
}

// Thread function for adding entries to the database.
void* add_thread(void* arg) {
    int start = (int) arg;
    for (int i = start; i < MAX_ENTRIES; i += MAX_THREADS) {
        add_entry(i);
    }
    pthread_exit(NULL);
}

// Thread function for removing entries from the database.
void* remove_thread(void* arg) {
    int start = (int) arg;
    for (int i = start; i < num_entries; i += MAX_THREADS) {
        remove_entry(i);
    }
    pthread_exit(NULL);
}

// Thread function for finding entries in the database.
void* find_thread(void* arg) {
    int start = (int) arg;
    for (int i = start; i < MAX_ENTRIES; i += MAX_THREADS) {
        int index = find_entry(i);
        if (index != -1) {
            printf("Entry %d found at index %d\n", i, index);
        }
    }
    pthread_exit(NULL);
}

// Main function.
int main() {
    pthread_t add_threads[MAX_THREADS];
    pthread_t remove_threads[MAX_THREADS];
    pthread_t find_threads[MAX_THREADS];

    // Initialize the read-write lock and database.
    pthread_rwlock_init(&db_lock, NULL);
    memset(db, 0, sizeof(db));

    // Create threads for adding entries to the database.
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&add_threads[i], NULL, add_thread, (void*) i);
    }

    // Wait for the add threads to finish.
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(add_threads[i], NULL);
    }

    // Create threads for removing entries from the database.
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&remove_threads[i], NULL, remove_thread, (void*) i);
    }

    // Wait for the remove threads to finish.
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(remove_threads[i], NULL);
    }

    // Create threads for finding entries in the database.
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&find_threads[i], NULL, find_thread, (void*) i);
    }

    // Wait for the find threads to finish.
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(find_threads[i], NULL);
    }

    // Destroy the read-write lock.
    pthread_rwlock_destroy(&db_lock);

    return 0;
}