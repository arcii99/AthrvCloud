//FormAI DATASET v1.0 Category: Database simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define DB_SIZE 10

//data structure to represent a database
typedef struct {
    int data[DB_SIZE];
    int count;
    pthread_mutex_t mutex;
} Database;

//function to initialize database
void init_db(Database* db) {
    db->count = 0;
    pthread_mutex_init(&db->mutex, NULL);
}

//function to add data to database
void add_data(Database* db, int data) {
    pthread_mutex_lock(&db->mutex);
    if (db->count < DB_SIZE) {
        db->data[db->count++] = data;
        printf("Added data %d\n", data);
    } else {
        printf("Database is full\n");
    }
    pthread_mutex_unlock(&db->mutex);
}

//function to remove data from database
bool remove_data(Database* db, int data) {
    bool success = false;
    pthread_mutex_lock(&db->mutex);
    for (int i = 0; i < db->count; i++) {
        if (db->data[i] == data) {
            db->data[i] = db->data[db->count - 1];
            db->count--;
            success = true;
            printf("Removed data %d\n", data);
            break;
        }
    }
    pthread_mutex_unlock(&db->mutex);
    return success;
}

//function to print all data in database
void print_data(Database* db) {
    printf("Data in database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d ", db->data[i]);
    }
    printf("\n");
}

//thread function to add data to database
void* add_thread_func(void* arg) {
    Database* db = (Database*) arg;
    for (int i = 0; i < 5; i++) {
        add_data(db, i + 1);
        sleep(1);
    }
    return NULL;
}

//thread function to remove data from database
void* remove_thread_func(void* arg) {
    Database* db = (Database*) arg;
    for (int i = 0; i < 5; i++) {
        remove_data(db, i + 1);
        sleep(1);
    }
    return NULL;
}

int main() {
    Database db;
    init_db(&db);
    
    pthread_t add_thread, remove_thread;
    pthread_create(&add_thread, NULL, add_thread_func, &db);
    pthread_create(&remove_thread, NULL, remove_thread_func, &db);

    pthread_join(add_thread, NULL);
    pthread_join(remove_thread, NULL);

    print_data(&db);
    return 0;
}