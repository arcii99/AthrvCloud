//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

// Define semaphore
sem_t sem;

// Define a global variable to hold the count of asterisks to be printed
int count = 0;

// Function to print the asterisks pattern
void print_pattern(int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Function to generate random numbers
int rand_num(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// Thread function to generate random numbers and add to the count variable
void *generate_count(void *arg) {
    while (true) {
        int num = rand_num(1, 10);
        sem_wait(&sem);
        count += num;
        printf("Generated %d. Count is now %d.\n", num, count);
        sem_post(&sem);
        sleep(rand_num(1, 3));
    }
}

// Thread function to print the pattern when the count variable reaches a multiple of 5
void *print_pattern_async(void *arg) {
    while (true) {
        sem_wait(&sem);
        if (count % 5 == 0 && count > 0) {
            printf("Count is %d. Printing pattern...\n", count);
            print_pattern(count);
            count = 0;
        }
        sem_post(&sem);
        sleep(rand_num(1, 3));
    }
}

int main() {
    // Initialize semaphore with value 1
    sem_init(&sem, 0, 1);

    // Create generate_count thread
    pthread_t gc_thread;
    if (pthread_create(&gc_thread, NULL, generate_count, NULL)) {
        fprintf(stderr, "Error creating generate_count thread!\n");
        return 1;
    }

    // Create print_pattern_async thread
    pthread_t pa_thread;
    if (pthread_create(&pa_thread, NULL, print_pattern_async, NULL)) {
        fprintf(stderr, "Error creating print_pattern_async thread!\n");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(gc_thread, NULL);
    pthread_join(pa_thread, NULL);

    // Destroy semaphore
    sem_destroy(&sem);

    return 0;
}