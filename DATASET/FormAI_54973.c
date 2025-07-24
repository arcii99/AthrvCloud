//FormAI DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_VALUES 1000

int values[MAX_VALUES];
int num_values = 0;
pthread_rwlock_t rwlock;

void init_index() {
    pthread_rwlock_init(&rwlock, NULL);
}

void insert_value(int value) {
    pthread_rwlock_wrlock(&rwlock);
    if(num_values < MAX_VALUES) {
        values[num_values] = value;
        num_values++;
    }
    pthread_rwlock_unlock(&rwlock);
}

void search_value(int value) {
    pthread_rwlock_rdlock(&rwlock);
    int found = 0;
    for(int i = 0; i < num_values; i++) {
        if(values[i] == value) {
            printf("Value %d found in index at position %d\n", value, i);
            found = 1;
            break; 
        }
    }
    if(!found) {
        printf("Value %d not found in index\n", value);
    }
    pthread_rwlock_unlock(&rwlock);
}

void print_index() {
    printf("Index contains the following values:\n");
    pthread_rwlock_rdlock(&rwlock);
    for(int i = 0; i < num_values; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    pthread_rwlock_unlock(&rwlock);
}

void *insert_thread(void *arg) {
    for(int i = 0; i < 5; i++) {
        int value = rand() % 100;
        insert_value(value);
        printf("Inserted value %d in index\n", value);
        usleep(1000);
    }
    return NULL;
}

void *search_thread(void *arg) {
    for(int i = 0; i < 5; i++) {
        int value = rand() % 100;
        search_value(value);
        usleep(1000);
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    init_index();

    pthread_t insert_t, search_t;
    pthread_create(&insert_t, NULL, insert_thread, NULL);
    pthread_create(&search_t, NULL, search_thread, NULL);

    pthread_join(insert_t, NULL);
    pthread_join(search_t, NULL);

    print_index();

    pthread_rwlock_destroy(&rwlock);

    return 0;
}