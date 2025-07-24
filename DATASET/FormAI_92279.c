//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define THREAD_COUNT 4

pthread_mutex_t mutex;
int spamCount = 0;

void* scanMessage(void* _message) {
    char* message = (char*)_message;
    // Here, scan the message for spam or unwanted content
    int isSpam = 0; // Set to 1 if spam is detected
    if (isSpam) {
        pthread_mutex_lock(&mutex); // Lock the mutex before accessing the shared variable
        spamCount++;
        pthread_mutex_unlock(&mutex); // Unlock the mutex after accessing the shared variable
    }
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    char* messages[10] = {"Message 1", "Message 2", "Message 3", "Message 4", "Message 5", "Message 6", "Message 7", "Message 8", "Message 9", "Message 10"};
    int i;
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex
    // Create threads to scan messages
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, scanMessage, (void*)messages[i]);
    }
    // Wait for threads to finish
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex); // Destroy the mutex
    printf("Spam count: %d\n", spamCount);
    return 0;
}