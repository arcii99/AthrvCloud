//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
/*
Airport Baggage Handling Simulation

This program simulates the baggage handling system in a busy airport.
It uses multiple threads to simulate the various components of the system
including conveyor belts, scanners, and baggage carts.

Author: [Your Name]
Date: [Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 7       // number of threads in system
#define MAX_BAGS 20         // maximum number of bags on conveyor belt
#define CONVEYOR_SPEED 1    // conveyor belt speed (seconds per bag)
#define SCANNER_SPEED 2     // scanner speed (seconds per bag)

int conveyor[MAX_BAGS];     // conveyor belt buffer
int num_bags = 0;           // number of bags on conveyor belt
int next_bag = 0;           // index of next bag on conveyor belt
sem_t conveyor_sem;         // semaphore for conveyor belt buffer
sem_t scanner_sem;          // semaphore for scanner
sem_t baggage_cart_sem;     // semaphore for baggage cart

void *conveyor_thread(void *arg);
void *scanner_thread(void *arg);
void *cart_thread(void *arg);

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    // initialize semaphores
    sem_init(&conveyor_sem, 0, MAX_BAGS);
    sem_init(&scanner_sem, 0, 1);
    sem_init(&baggage_cart_sem, 0, 0);

    // initialize conveyor belt buffer
    for (i = 0; i < MAX_BAGS; i++) {
        conveyor[i] = 0;
    }

    // create threads
    pthread_create(&threads[0], NULL, conveyor_thread, NULL);
    pthread_create(&threads[1], NULL, scanner_thread, NULL);
    pthread_create(&threads[2], NULL, cart_thread, NULL);
    pthread_create(&threads[3], NULL, cart_thread, NULL);
    pthread_create(&threads[4], NULL, cart_thread, NULL);
    pthread_create(&threads[5], NULL, cart_thread, NULL);
    pthread_create(&threads[6], NULL, cart_thread, NULL);

    // join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // destroy semaphores
    sem_destroy(&conveyor_sem);
    sem_destroy(&scanner_sem);
    sem_destroy(&baggage_cart_sem);

    return 0;
}

void *conveyor_thread(void *arg) {
    int i;

    while (1) {
        // wait for space on conveyor belt
        sem_wait(&conveyor_sem);

        // add bag to conveyor belt
        conveyor[next_bag] = 1;
        num_bags++;
        printf("Added bag %d to conveyor belt\n", next_bag+1);
        next_bag = (next_bag + 1) % MAX_BAGS;

        // wait for conveyor belt to move
        sleep(CONVEYOR_SPEED);

        // signal that bag is ready for scanning
        sem_post(&scanner_sem);
    }
}

void *scanner_thread(void *arg) {
    int bag_num;

    while (1) {
        // wait for bag to be available for scanning
        sem_wait(&scanner_sem);

        // scan bag
        for (bag_num = 0; bag_num < MAX_BAGS; bag_num++) {
            if (conveyor[bag_num] == 1) {
                conveyor[bag_num] = 2;
                printf("Scanned bag %d\n", bag_num+1);
                break;
            }
        }

        // wait for scanner to finish
        sleep(SCANNER_SPEED);

        // signal that bag is ready for pickup
        sem_post(&baggage_cart_sem);
    }
}

void *cart_thread(void *arg) {
    int cart_num = *(int*)arg;
    int bag_num;

    while (1) {
        // wait for bag to be available for pickup
        sem_wait(&baggage_cart_sem);

        // pick up bag
        for (bag_num = 0; bag_num < MAX_BAGS; bag_num++) {
            if (conveyor[bag_num] == 2) {
                conveyor[bag_num] = 0;
                num_bags--;
                printf("Cart %d picked up bag %d\n", cart_num+1, bag_num+1);
                break;
            }
        }

        // wait for cart to move
        sleep(2);

        // signal that cart is available for next bag
        sem_post(&conveyor_sem);
    }
}