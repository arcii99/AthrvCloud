//FormAI DATASET v1.0 Category: Digital Diary ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_ENTRIES 10

// Struct to hold each diary entry
typedef struct Entry {
    int day;
    int month;
    int year;
    char* content;
} Entry;

// Global diary array and current index
Entry diary[MAX_ENTRIES];
int currentIndex = 0;

// Mutex for thread safety
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a new entry to the diary
void addEntry(int day, int month, int year, char* content) {
    // Lock the mutex to ensure thread safety
    pthread_mutex_lock(&mutex);
    
    // Check if there is space in the diary
    if (currentIndex >= MAX_ENTRIES) {
        printf("Diary is full!\n");
    } else {
        // Create a new entry and add it to the diary
        Entry newEntry;
        newEntry.day = day;
        newEntry.month = month;
        newEntry.year = year;
        newEntry.content = content;
        
        diary[currentIndex] = newEntry;
        currentIndex++;
    }
    
    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// Function to print all entries in the diary
void printDiary() {
    // Lock the mutex to ensure thread safety
    pthread_mutex_lock(&mutex);
    
    // Loop through the diary and print each entry
    for (int i = 0; i < currentIndex; i++) {
        printf("Entry %d:\n", i+1);
        printf("Date: %d/%d/%d\n", diary[i].day, diary[i].month, diary[i].year);
        printf("Content: %s\n\n", diary[i].content);
    }
    
    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// Function to simulate adding entries to the diary
void* addEntries(void* arg) {
    // Lock the mutex to ensure thread safety
    pthread_mutex_lock(&mutex);
    
    // Generate some random entries to add to the diary
    for (int i = 0; i < 5; i++) {
        int day = rand() % 28 + 1;
        int month = rand() % 12 + 1;
        int year = 2022;
        char* content = "This is a test entry!";
        
        addEntry(day, month, year, content);
    }
    
    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Create two threads to add entries to the diary
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, addEntries, NULL);
    pthread_create(&thread2, NULL, addEntries, NULL);
    
    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    // Print all entries in the diary
    printDiary();
    
    return 0;
}