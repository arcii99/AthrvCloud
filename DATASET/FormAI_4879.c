//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Array of possible conspiracy theories
char *conspiracy_theories[] = {
    "The moon landing was faked by the government",
    "Aliens are among us and are controlling the government",
    "9/11 was an inside job orchestrated by the government",
    "The Illuminati secretly controls the world",
    "The Earth is flat and governments are hiding the truth",
    "Vaccines cause autism and they are being pushed by the government",
    // and so on
};

// Mutex for shared data access
pthread_mutex_t lock;

// Function to generate a random conspiracy theory
void *generate_conspiracy_theory(void *arg)
{
    int thread_id = *(int *)arg;
    int index = rand() % (sizeof(conspiracy_theories) / sizeof(char *));
    
    // Lock mutex for shared data access
    pthread_mutex_lock(&lock);
    
    printf("Thread %d generated conspiracy theory: %s\n", thread_id, conspiracy_theories[index]);
    
    // Unlock mutex after use
    pthread_mutex_unlock(&lock);
    
    pthread_exit(NULL);
}

int main()
{
    int num_threads = 5;
    int thread_ids[num_threads];
    
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);
    
    pthread_t threads[num_threads];
    
    // Generate threads
    for(int i = 0; i < num_threads; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, generate_conspiracy_theory, &thread_ids[i]);
    }
    
    // Wait for threads to finish
    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Destroy mutex
    pthread_mutex_destroy(&lock);
    
    return 0;
}