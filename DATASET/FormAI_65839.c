//FormAI DATASET v1.0 Category: Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of message
#define NUM_THREADS 4 // Number of worker threads

char message[MAX_LENGTH]; // Shared variable to encrypt
int message_length; // Length of actual message (not including null-terminator)
int position = 0; // Position of the message to be encrypted

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex to protect shared variable

void* encrypt(void *arg) {
    int thread_id = *((int *) arg);
    int start = position;
    int end = start + message_length/NUM_THREADS;
    position = end; // Move position for next thread
    
    for(int i = start; i < end; i++) {
        pthread_mutex_lock(&mutex);
        message[i] = message[i] + thread_id;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    printf("Enter message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);
    message_length = strlen(message) - 1; // Remove null-terminator from length
    
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, encrypt, &thread_ids[i]);
    }
    
    // Wait for all threads to finish execution
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Encrypted message: ");
    for(int i = 0; i < message_length; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
    
    pthread_exit(NULL);
}