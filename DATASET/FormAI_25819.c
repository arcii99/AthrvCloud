//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_BAGGAGE 100 // maximum number of bags that can fit on conveyor belt

// global variables
int baggage_count = 0; // current number of bags on conveyor belt
bool is_running = true; // flag for simulator loop

sem_t conveyor_sem; // semaphore to control access to conveyor belt
sem_t bay_sem; // semaphore to control access to baggage bay

// function declarations
void *conveyor(void *arg);
void *baggage_bay(void *arg);

int main() {
    pthread_t thread_conveyor, thread_bay;

    // initialize semaphores
    sem_init(&conveyor_sem, 0, 1); // conveyor semaphore starts unlocked
    sem_init(&bay_sem, 0, 0); // baggage bay semaphore starts locked

    // create threads
    pthread_create(&thread_conveyor, NULL, conveyor, NULL);
    pthread_create(&thread_bay, NULL, baggage_bay, NULL);

    // run simulation
    while (is_running) {
        // randomly add bags to conveyor belt
        if (rand() % 2 == 0 && baggage_count < MAX_BAGGAGE) {
            sem_wait(&conveyor_sem); // lock conveyor semaphore
            baggage_count++; // add bag to conveyor belt
            printf("Added bag to conveyor belt! Current count: %d\n", baggage_count);
            sem_post(&conveyor_sem); // unlock conveyor semaphore
        }

        // sleep for random amount of time
        int sleep_time = rand() % 2 + 1;
        sleep(sleep_time);
    }

    // join threads
    pthread_join(thread_conveyor, NULL);
    pthread_join(thread_bay, NULL);

    // destroy semaphores
    sem_destroy(&conveyor_sem);
    sem_destroy(&bay_sem);

    return 0;
}

void *conveyor(void *arg) {
    while (is_running) {
        sem_wait(&conveyor_sem); // lock conveyor semaphore

        // check if baggage bay is empty and there is baggage on the conveyor belt
        if (baggage_count > 0) {
            sem_wait(&bay_sem); // lock baggage bay semaphore

            // remove bag from conveyor belt and add to baggage bay
            baggage_count--;
            printf("Moved bag to baggage bay! Current count: %d\n", baggage_count);

            sem_post(&bay_sem); // unlock baggage bay semaphore
        }

        sem_post(&conveyor_sem); // unlock conveyor semaphore
    }

    pthread_exit(NULL);
}

void *baggage_bay(void *arg) {
    while (is_running) {
        sem_wait(&bay_sem); // lock baggage bay semaphore

        // remove bag from baggage bay
        printf("Removed bag from baggage bay! Current count: %d\n", baggage_count);

        sem_post(&bay_sem); // unlock baggage bay semaphore
    }

    pthread_exit(NULL);
}