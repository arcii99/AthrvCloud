//FormAI DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_DIARY_ENTRIES 10

int num_entries = 0; // number of diary entries made
int curr_index = 0; // current index in the diary
char *diary[MAX_DIARY_ENTRIES]; // array to hold diary entries
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // mutex lock for thread safety

void add_entry(char *entry) {
    pthread_mutex_lock(&mutex); // acquire lock
    if (num_entries == MAX_DIARY_ENTRIES) { // diary is full
        printf("Diary is full. Cannot make any more entries.\n");
        pthread_mutex_unlock(&mutex); // release lock
        return;
    }
    diary[curr_index] = entry; // add new entry
    num_entries++;
    curr_index = (curr_index + 1) % MAX_DIARY_ENTRIES; // wrap around if necessary
    printf("Entry added successfully.\n");
    pthread_mutex_unlock(&mutex); // release lock
}

void *get_entry(void *arg) {
    pthread_mutex_lock(&mutex); // acquire lock
    if (num_entries == 0) { // diary is empty
        printf("Diary is empty. No entries to retrieve.\n");
        pthread_mutex_unlock(&mutex); // release lock
        return NULL;
    }
    int index = rand() % num_entries; // get a random index to retrieve entry from
    printf("Retrieving entry at index %d.\n%s\n", index, diary[index]);
    pthread_mutex_unlock(&mutex); // release lock
    return NULL;
}

int main() {
    pthread_t threads[5]; // array of threads
    char *entry1 = "Today was a great day!";
    char *entry2 = "I went to the park with my friends.";
    char *entry3 = "I learned how to code in C today.";
    char *entry4 = "I ate pizza for dinner.";
    char *entry5 = "I finished reading a good book.";
    
    // create threads
    pthread_create(&threads[0], NULL, get_entry, NULL);
    pthread_create(&threads[1], NULL, get_entry, NULL);
    pthread_create(&threads[2], NULL, get_entry, NULL);
    pthread_create(&threads[3], NULL, get_entry, NULL);
    pthread_create(&threads[4], NULL, get_entry, NULL);
    
    // add entries
    add_entry(entry1);
    add_entry(entry2);
    add_entry(entry3);
    add_entry(entry4);
    add_entry(entry5);
    
    // join threads
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}