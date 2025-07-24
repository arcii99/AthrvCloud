//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ENTRIES 1000  // maximum number of entries in the database

// structure defining a database entry
typedef struct {
    int id;
    char name[50];
    int age;
} Entry;

Entry database[MAX_ENTRIES];  // array to store the database entries
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // mutex to synchronize access to the database
int num_entries = 0;  // variable to keep track of the number of entries in the database

// function to add an entry to the database
void add_entry(int id, char* name, int age) {
    pthread_mutex_lock(&mutex);  // acquire the lock
    if (num_entries >= MAX_ENTRIES) {
        printf("Database is full!\n");
    } else {
        Entry entry;
        entry.id = id;
        strcpy(entry.name, name);
        entry.age = age;
        database[num_entries] = entry;
        num_entries++;
    }
    pthread_mutex_unlock(&mutex);  // release the lock
}

// function to print all the entries in the database
void print_database() {
    pthread_mutex_lock(&mutex);  // acquire the lock
    if (num_entries == 0) {
        printf("Database is empty!\n");
    } else {
        printf("ID\tName\t\tAge\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%d\t%s\t\t%d\n", database[i].id, database[i].name, database[i].age);
        }
    }
    pthread_mutex_unlock(&mutex);  // release the lock
}

// thread function to add entries to the database
void* add_thread(void* arg) {
    for (int i = 0; i < 10; i++) {
        int id = rand() % 10000 + 1;
        char name[50];
        sprintf(name, "Entry%d", id);
        int age = rand() % 50 + 18;
        add_entry(id, name, age);
        usleep(1000);  // sleep for 1 millisecond to simulate a delay
    }
    pthread_exit(NULL);
}

// thread function to print the database
void* print_thread(void* arg) {
    while (1) {
        print_database();
        usleep(10000);  // sleep for 10 milliseconds to simulate a delay
    }
    pthread_exit(NULL);
}

int main() {
    // create threads for adding entries and printing the database
    pthread_t add_t, print_t;
    pthread_create(&add_t, NULL, add_thread, NULL);
    pthread_create(&print_t, NULL, print_thread, NULL);
    
    // wait for the threads to finish
    pthread_join(add_t, NULL);
    pthread_join(print_t, NULL);
    
    return 0;
}