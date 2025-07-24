//FormAI DATASET v1.0 Category: modern Encryption ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MESSAGE_SIZE 100
#define KEY_SIZE 10

char message[MESSAGE_SIZE]; // message to be encrypted
char encrypted_message[MESSAGE_SIZE]; // encrypted message
char key[KEY_SIZE]; // encryption key

pthread_mutex_t lock; // mutex lock for thread synchronization

void* encryption_worker(void* args) {
    int i;
    char* thread_id = (char*) args; // thread identifier
    printf("Thread %s: Waiting for lock...\n", thread_id);
    pthread_mutex_lock(&lock); // acquire the lock
    printf("Thread %s: Acquired lock.\n", thread_id);
    
    // Encrypt the message using the key
    for (i = 0; i < MESSAGE_SIZE; i++) {
        encrypted_message[i] = message[i] ^ key[i % KEY_SIZE];
    }
    
    pthread_mutex_unlock(&lock); // release the lock
    printf("Thread %s: Released lock.\n", thread_id);
    pthread_exit(NULL); // exit the thread
}

int main() {
    pthread_t threads[2]; // array of threads
    int i, rc;
    char thread_ids[2][2] = {"A", "B"}; // thread identifiers
    
    // Get the message and encryption key from the user
    printf("Enter the message to be encrypted: ");
    fgets(message, MESSAGE_SIZE, stdin);
    printf("Enter the encryption key (10 characters): ");
    fgets(key, KEY_SIZE, stdin);
    
    // Create two threads to encrypt the message
    pthread_mutex_init(&lock, NULL); // initialize the mutex lock
    for (i = 0; i < 2; i++) {
        rc = pthread_create(&threads[i], NULL, encryption_worker, (void*) thread_ids[i]);
        if (rc) {
            printf("ERROR: Unable to create thread %d\n", i);
            exit(-1);
        }
    }
    
    // Wait for the threads to finish
    for (i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
    
    pthread_mutex_destroy(&lock); // destroy the mutex lock
    pthread_exit(NULL); // exit the program
}