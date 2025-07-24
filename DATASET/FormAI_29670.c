//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <openssl/sha.h>

#define BUFFER_SIZE 1024
#define NUM_THREADS 4

pthread_mutex_t hash_mutex;
char buffer[BUFFER_SIZE];
int buffer_index = 0;
unsigned char hash[SHA256_DIGEST_LENGTH];

void *compute_hash(void *dummy_ptr) {
    int i, len;
    unsigned char buffer_copy[BUFFER_SIZE];
    
    while (1) {
        // Lock the buffer
        pthread_mutex_lock(&hash_mutex);
        if (buffer_index == 0) {
            // Buffer is empty, unlock and wait for more input
            pthread_mutex_unlock(&hash_mutex);
            if (hash[0] != 0) {
                // Hash has been computed, exit the thread
                pthread_exit(NULL);
            }
            continue;
        }
        
        // Copy buffer content and index
        memcpy(buffer_copy, buffer, BUFFER_SIZE);
        len = buffer_index;
        
        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);
        buffer_index = 0;
        
        // Unlock buffer
        pthread_mutex_unlock(&hash_mutex);
        
        // Compute hash of buffer_copy
        SHA256(buffer_copy, len, hash);
    }
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    
    // Initialize mutex
    pthread_mutex_init(&hash_mutex, NULL);
    
    // Create worker threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, compute_hash, NULL);
    }
    
    // Main loop
    while (1) {
        // Read input from user
        printf("Enter text to hash: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        // Calculate length of input
        buffer_index = strlen(buffer);
        
        // Print hash
        pthread_mutex_lock(&hash_mutex);
        for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            printf("%02x", hash[i]);
        }
        printf("\n");
        pthread_mutex_unlock(&hash_mutex);
    }
    
    // Cleanup
    pthread_mutex_destroy(&hash_mutex);
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}