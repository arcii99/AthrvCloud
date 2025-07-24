//FormAI DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_NUM_RECORDS 10000

struct Record {
    int id;
    char name[50];
    int age;
};

struct Index {
    char name[50];
    int record_num;
};

struct Database {
    struct Record records[MAX_NUM_RECORDS];
    struct Index indexes[MAX_NUM_RECORDS];
    int num_records;
    int num_indexes;
    pthread_mutex_t mutex;
};

void database_init(struct Database *db) {
    db->num_records = 0;
    db->num_indexes = 0;
    pthread_mutex_init(&db->mutex, NULL);
}

int database_insert_record(struct Database *db, struct Record record) {
    pthread_mutex_lock(&db->mutex);
    if (db->num_records == MAX_NUM_RECORDS) {
        pthread_mutex_unlock(&db->mutex);
        return -1; // Database is full
    }
    db->records[db->num_records] = record;
    db->num_records++;
    pthread_mutex_unlock(&db->mutex);
    return 0;
}

int database_insert_index(struct Database *db, char name[], int record_num) {
    pthread_mutex_lock(&db->mutex);
    if (db->num_indexes == MAX_NUM_RECORDS) {
        pthread_mutex_unlock(&db->mutex);
        return -1; // Index table is full
    }
    strcpy(db->indexes[db->num_indexes].name, name);
    db->indexes[db->num_indexes].record_num = record_num;
    db->num_indexes++;
    pthread_mutex_unlock(&db->mutex);
    return 0;
}

int database_find_record_by_name(struct Database *db, char name[], struct Record *record) {
    pthread_mutex_lock(&db->mutex);
    for (int i = 0; i < db->num_indexes; i++) {
        if (strcmp(db->indexes[i].name, name) == 0) {
            *record = db->records[db->indexes[i].record_num];
            pthread_mutex_unlock(&db->mutex);
            return 0; // Record found
        }
    }
    pthread_mutex_unlock(&db->mutex);
    return -1; // Record not found
}

void *insert_thread(void *arg) {
    struct Database *db = (struct Database *) arg;
    struct Record record = { 1, "John Smith", 35 };
    int result = database_insert_record(db, record);
    if (result == 0) {
        database_insert_index(db, record.name, db->num_records - 1); // Insert an index for the new record
    }
    return NULL;
}

void *find_thread(void *arg) {
    struct Database *db = (struct Database *) arg;
    struct Record record;
    int result = database_find_record_by_name(db, "John Smith", &record);
    if (result == 0) {
        printf("Found record: id=%d, name=%s, age=%d\n", record.id, record.name, record.age);
    } else {
        printf("Record not found\n");
    }
    return NULL;
}

int main() {
    struct Database db;
    database_init(&db);

    pthread_t insert_threads[10];
    pthread_t find_threads[10];
    for (int i = 0; i < 10; i++) {
        pthread_create(&insert_threads[i], NULL, insert_thread, &db);
        pthread_create(&find_threads[i], NULL, find_thread, &db);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(insert_threads[i], NULL);
        pthread_join(find_threads[i], NULL);
    }

    return 0;
}