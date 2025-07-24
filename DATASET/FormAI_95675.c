//FormAI DATASET v1.0 Category: Database simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

//structure that defines a record in the database
typedef struct {
    int id;
    char name[20];
    int age;
} record;

//global variables
record database[10];
int database_size = 0;
int current_record_id = 0;

//mutex for thread synchronization
pthread_mutex_t lock;

//function to add a new record to the database
void add_record(const char* name, int age) {
    pthread_mutex_lock(&lock);
    if(database_size >= 10) {
        printf("Database is full!\n");
    } else {
        record new_record;
        new_record.id = current_record_id++;
        strncpy(new_record.name, name, 20);
        new_record.age = age;
        database[database_size++] = new_record;
    }
    pthread_mutex_unlock(&lock);
}

//function to print all records in the database
void print_database() {
    pthread_mutex_lock(&lock);
    if(database_size == 0) {
        printf("Database is empty!\n");
    } else {
        for(int i=0; i<database_size; i++) {
            printf("Record %d: name=%s, age=%d\n", database[i].id, database[i].name, database[i].age);
        }
    }
    pthread_mutex_unlock(&lock);
}

//function to simulate the database by running multiple threads
void* database_simulation(void* args) {
    int thread_id = *(int*)args;
    char name[20];
    sprintf(name, "User_%d", thread_id);
    int age = rand() % 50 + 20;
    printf("Thread %d: adding record with name=%s, age=%d\n", thread_id, name, age);
    add_record(name, age);
    usleep(rand() % 10000 + 1000);
    printf("Thread %d: printing database\n", thread_id);
    print_database();
    return NULL;
}

//main function for the program
int main() {
    //initialize the mutex
    pthread_mutex_init(&lock, NULL);
    
    //create multiple threads to simulate database actions
    pthread_t threads[5];
    int thread_ids[5];
    for(int i=0; i<5; i++) {
        thread_ids[i] = i+1;
        pthread_create(&threads[i], NULL, database_simulation, (void*)&thread_ids[i]);
    }
    for(int i=0; i<5; i++) {
        pthread_join(threads[i], NULL);
    }
    
    //destroy the mutex
    pthread_mutex_destroy(&lock);
    
    return 0;
}