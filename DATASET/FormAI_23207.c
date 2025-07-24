//FormAI DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define ARRAY_SIZE 1000000

int array[ARRAY_SIZE];

bool found = false;
int value_to_find;
pthread_mutex_t lock;

void *search_array(void *arg) {
    int lower_bound = *(int*)arg;
    int upper_bound = lower_bound + (ARRAY_SIZE/2);
    
    for (int i = lower_bound; i < upper_bound; i++) {
        pthread_mutex_lock(&lock);
        if (array[i] == value_to_find) {
            found = true;
        }
        pthread_mutex_unlock(&lock);
    }
    
    pthread_exit(0);
}

int main(int argc, char **argv) {
    srand(time(NULL));
    
    // Initialize array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }
    
    // Get value to search for
    printf("Enter value to find: ");
    scanf("%d", &value_to_find);
    
    // Initialize mutex lock
    pthread_mutex_init(&lock, NULL);
    
    // Create two threads to search the array
    pthread_t thread1, thread2;
    
    int lower_bound1 = 0;
    int lower_bound2 = ARRAY_SIZE/2;
    
    pthread_create(&thread1, NULL, search_array, &lower_bound1);
    pthread_create(&thread2, NULL, search_array, &lower_bound2);
    
    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    // Check if value was found
    if (found) {
        printf("Value found in array!\n");
    } else {
        printf("Value not found in array.\n");
    }
    
    // Destroy mutex lock
    pthread_mutex_destroy(&lock);
    
    return 0;
}