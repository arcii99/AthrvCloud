//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_BAGGAGE 20 // maximum number of baggage that can be handled at once

sem_t conveyor; // semaphore for the conveyor
sem_t scanner; // semaphore for the scanner

int baggage_count = 0; // current number of baggage on the conveyor

void *conveyor_loader(void *arg) {
    while(1) {
        sem_wait(&conveyor); // wait for space on the conveyor
        
        printf("Loading baggage onto conveyor...\n");
        baggage_count++;
        
        if(baggage_count >= MAX_BAGGAGE) {
            printf("Conveyor is full. Waiting...\n");
        }
        
        sem_post(&scanner); // signal the scanner that baggage is on the conveyor
    }
}

void *scanner_handler(void *arg) {
    while(1) {
        sem_wait(&scanner); // wait for baggage on the conveyor
        
        printf("Scanning baggage...\n");
        baggage_count--;
        
        sem_post(&conveyor); // signal the conveyor that space is available
    }
}

int main() {
    sem_init(&conveyor, 0, MAX_BAGGAGE); // initialize conveyor semaphore
    sem_init(&scanner, 0, 0); // initialize scanner semaphore
    
    pthread_t conveyor_thread, scanner_thread;
    pthread_create(&conveyor_thread, NULL, conveyor_loader, NULL);
    pthread_create(&scanner_thread, NULL, scanner_handler, NULL);
    
    pthread_join(conveyor_thread, NULL);
    pthread_join(scanner_thread, NULL);
    
    sem_destroy(&conveyor);
    sem_destroy(&scanner);
    
    return 0;
}