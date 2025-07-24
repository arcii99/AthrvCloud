//FormAI DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_ENTRIES 10000

struct Entry {
    int key;
    char value[256];
};

struct Index {
    int size;
    struct Entry* entries;
};

struct Worker {
    int id;
    pthread_t thread;
    struct Index* index;
    volatile bool running;
};

struct Database {
    pthread_mutex_t mutex;
    struct Index index;
    struct Worker workers[MAX_THREADS];
    volatile int worker_count;
    volatile bool indexing;
};

void init_index(struct Index* index, int size) {
    index->size = size;
    index->entries = (struct Entry*) malloc(size * sizeof(struct Entry));
    memset(index->entries, 0, size * sizeof(struct Entry));
}

void print_entry(struct Entry* entry) {
    printf("{ key: %d, value: %s }\n", entry->key, entry->value);
}

void print_index(struct Index* index) {
    printf("index:\n");
    for (int i = 0; i < index->size; i++) {
        struct Entry* entry = &index->entries[i];
        if (entry->key != 0) print_entry(entry);
    }
}

void add_entry(struct Index* index, int key, const char* value) {
    struct Entry* entry = &index->entries[key];
    entry->key = key;
    strncpy(entry->value, value, sizeof(entry->value));
}

void remove_entry(struct Index* index, int key) {
    struct Entry* entry = &index->entries[key];
    entry->key = 0;
    memset(entry->value, 0, sizeof(entry->value));
}

int find_next_key(struct Index* index, int start) {
    for (int i = start; i < index->size; i++) {
        if (index->entries[i].key == 0) return i;
    }
    return -1;
}

void process_entries(struct Worker* worker, int start, int end) {
    for (int i = start; i < end; i++) {
        if (!worker->running) return;
        struct Entry* entry = &worker->index->entries[i];
        if (entry->key != 0) printf("worker %d processing entry %d\n", worker->id, entry->key);
    }
}

void* work(void* arg) {
    struct Worker* worker = (struct Worker*) arg;
    int start = worker->id * (MAX_ENTRIES / worker->index->size);
    int end = start + (MAX_ENTRIES / worker->index->size);
    while (worker->running) {
        process_entries(worker, start, end);
        usleep(10000);
    }
    return NULL;
}

void start_workers(struct Database* db) {
    for (int i = 0; i < db->worker_count; i++) {
        struct Worker* worker = &db->workers[i];
        worker->index = &db->index;
        worker->running = true;
        pthread_create(&worker->thread, NULL, work, worker);
    }
}

void stop_workers(struct Database* db) {
    for (int i = 0; i < db->worker_count; i++) {
        struct Worker* worker = &db->workers[i];
        worker->running = false;
        pthread_join(worker->thread, NULL);
    }
}

void index_database(struct Database* db) {
    db->indexing = true;
    int next_key = find_next_key(&db->index, 0);
    while (next_key != -1) {
        if (!db->indexing) break;
        printf("indexing key %d\n", next_key);
        add_entry(&db->index, next_key, "value");
        next_key = find_next_key(&db->index, next_key + 1);
    }
}

void* index_database_async(void* arg) {
    struct Database* db = (struct Database*) arg;
    pthread_mutex_lock(&db->mutex);
    index_database(db);
    pthread_mutex_unlock(&db->mutex);
    return NULL;
}

void start_indexing(struct Database* db) {
    pthread_create(&db->workers[db->worker_count++].thread, NULL, index_database_async, db);
}

void stop_indexing(struct Database* db) {
    db->indexing = false;
    stop_workers(db);
}

int main() {
    struct Database db = { .mutex = PTHREAD_MUTEX_INITIALIZER };

    init_index(&db.index, MAX_ENTRIES);
    start_workers(&db);

    start_indexing(&db);
    printf("press enter to stop indexing...\n");
    getchar();
    stop_indexing(&db);

    print_index(&db.index);

    free(db.index.entries);
    return 0;
}