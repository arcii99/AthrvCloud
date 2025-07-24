//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_BAGS 100   //total number of bags to be processed
#define MAX_WEIGHT 50  //maximum weight for a bag in kg
#define CONVEYOR_CAPACITY 10 //capacity of the conveyor belt

sem_t conveyor, screening, loading;  //semaphores for each station
int total_weight = 0;  //total weight of bags processed
int rejected_bags = 0;  //number of bags rejected due to weight
int loaded_bags = 0;  //number of bags successfully loaded onto plane

void *conveyor_belt(void *arg) {
    int bags_on_belt = 0;
    for (int i = 1; i <= NUM_BAGS; i++) {
        if (bags_on_belt < CONVEYOR_CAPACITY) {
            sem_wait(&conveyor);  //wait for space on conveyor belt
            printf("Bag %d has been placed on the conveyor belt.\n", i);
            bags_on_belt++;
            sem_post(&screening);  //notify screening station of new bag
        }
        else {
            i--;  //don't advance to next bag until space on belt
            sleep(1);  //simulate delay in belt moving
        }
    }
    pthread_exit(NULL);
}

void *security_screening(void *arg) {
    int current_bag = 1;
    while (current_bag <= NUM_BAGS) {
        sem_wait(&screening);  //wait for new bag on conveyor
        int bag_weight = rand() % (MAX_WEIGHT + 1);
        printf("Bag %d weighs %d kg.\n", current_bag, bag_weight);
        if (bag_weight > MAX_WEIGHT) {
            printf("Bag %d has been rejected and must be removed.\n", current_bag);
            rejected_bags++;
        }
        else {
            total_weight += bag_weight;
            sem_post(&loading);  //notify loading station of approved bag
        }
        current_bag++;
        sleep(2);  //simulate delay in screening process
    }
    pthread_exit(NULL);
}

void *loading_plane(void *arg) {
    int bags_loaded = 0;
    while (bags_loaded < NUM_BAGS - rejected_bags) {
        sem_wait(&loading);  //wait for approved bag
        printf("Bag %d has been loaded onto the plane.\n", bags_loaded + 1);
        bags_loaded++;
        loaded_bags++;
        sem_post(&conveyor);  //notify conveyor of space on belt
    }
    pthread_exit(NULL);
}

int main() {
    sem_init(&conveyor, 0, CONVEYOR_CAPACITY);
    sem_init(&screening, 0, 0);
    sem_init(&loading, 0, 0);

    pthread_t conveyor_belt_thread, screening_thread, loading_thread;

    pthread_create(&conveyor_belt_thread, NULL, conveyor_belt, NULL);
    pthread_create(&screening_thread, NULL, security_screening, NULL);
    pthread_create(&loading_thread, NULL, loading_plane, NULL);

    pthread_join(conveyor_belt_thread, NULL);
    pthread_join(screening_thread, NULL);
    pthread_join(loading_thread, NULL);

    printf("%d bags were successfully loaded onto the plane.\n", loaded_bags);
    printf("%d bags were rejected due to weight.\n", rejected_bags);
    printf("The total weight of bags processed was %d kg.\n", total_weight);

    sem_destroy(&conveyor);
    sem_destroy(&screening);
    sem_destroy(&loading);

    return 0;
}