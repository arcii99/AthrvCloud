//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Romeo and Juliet
/* Enter stage left: The C Threading Library Implementation!
 * A library like none other, with tasks and threads aplenty.
 * Romeo and Juliet, our star-crossed lovers
 * shall use this library to write their story.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Threads for each of our lovers
pthread_t romeo_thread;
pthread_t juliet_thread;

// Mutex to protect the shared resource of Romeo and Juliet's love letters
pthread_mutex_t love_mutex;

// Love letters written by each lover
char* romeo_letter = NULL;
char* juliet_letter = NULL;

// Function that Romeo's thread will execute
void* romeo_task(void* arg) {
    while(1) {
        // Romeo writes his love letter
        pthread_mutex_lock(&love_mutex);
        romeo_letter = "Juliet, my love for you burns with the fire of a thousand suns!";
        pthread_mutex_unlock(&love_mutex);

        // Romeo sleeps until it is time to write his next letter
        sleep(2);
    }
}

// Function that Juliet's thread will execute
void* juliet_task(void* arg) {
    while(1) {
        // Juliet writes her love letter
        pthread_mutex_lock(&love_mutex);
        juliet_letter = "Romeo, my heart beats for you and you alone!";
        pthread_mutex_unlock(&love_mutex);

        // Juliet sleeps until it is time to write her next letter
        sleep(3);
    }
}

int main() {
    // Initialize love_mutex before creating threads
    if(pthread_mutex_init(&love_mutex, NULL) != 0) {
        printf("Mutex initialization failed!\n");
        return 1;
    }

    // Create threads for Romeo and Juliet
    if(pthread_create(&romeo_thread, NULL, &romeo_task, NULL) != 0) {
        printf("Thread creation failed!\n");
        return 1;
    }

    if(pthread_create(&juliet_thread, NULL, &juliet_task, NULL) != 0) {
        printf("Thread creation failed!\n");
        return 1;
    }

    // Main thread simulates reading and reacting to the love letters
    while(1) {
        pthread_mutex_lock(&love_mutex);

        // If there is no letter from Romeo or Juliet yet, main thread waits
        if(romeo_letter == NULL && juliet_letter == NULL) {
            pthread_mutex_unlock(&love_mutex);
            continue;
        }

        // If there is a letter from Romeo, print it and react to it
        if(romeo_letter != NULL) {
            printf("Romeo's letter: %s\n", romeo_letter);
            printf("Juliet reacts: Oh, Romeo! I love you too!\n");

            // Free the memory of romeo_letter and set it to NULL again
            free(romeo_letter);
            romeo_letter = NULL;
        }

        // If there is a letter from Juliet, print it and react to it
        if(juliet_letter != NULL) {
            printf("Juliet's letter: %s\n", juliet_letter);
            printf("Romeo reacts: Juliet, you have my heart forever!\n");

            // Free the memory of juliet_letter and set it to NULL again
            free(juliet_letter);
            juliet_letter = NULL;
        }

        pthread_mutex_unlock(&love_mutex);

        // Main thread sleeps between love letter readings to simulate time passing
        sleep(1);
    }

    // Destroy love_mutex after threads have finished executing
    pthread_mutex_destroy(&love_mutex);

    // Exit gracefully
    return 0;
}