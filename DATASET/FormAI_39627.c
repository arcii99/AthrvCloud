//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t elevator_thread;
pthread_t passenger_threads[10];

int current_floor = 1;
int passenger_floors[10] = {10, 7, 3, 5, 8, 1, 6, 4, 2, 9};

void* elevator(void* arg) {
    while(1){
        // check if there are any passengers waiting on this floor
        for(int i=0; i<10; i++){
            if(passenger_floors[i] == current_floor){
                printf("Passenger %d enters elevator!\n", i+1);
                passenger_floors[i] = 0;
            }
        }

        printf("Elevator is at floor %d\n", current_floor);
        // move elevator to the next floor
        if(current_floor == 10){
            current_floor = 1;
        } else {
            current_floor++;
        }
        // wait for 2 seconds before moving to next floor
        sleep(2);
    }
}

void* passenger(void* arg){
    int* floor = (int*) arg;
    printf("Passenger waiting on floor %d\n", *floor);
    // wait until elevator arrives on this floor
    while(current_floor != *floor){
        sleep(1);
    }
    printf("Passenger enters elevator on floor %d\n", *floor);
}

int main() {
    // create elevator thread
    pthread_create(&elevator_thread, NULL, elevator, NULL);
    // create passenger threads
    for(int i=0; i<10; i++){
        int* floor = &passenger_floors[i];
        pthread_create(&passenger_threads[i], NULL, passenger, floor);
    }

    // join elevator thread
    pthread_join(elevator_thread, NULL);
    // join passenger threads
    for(int i=0; i<10; i++){
        pthread_join(passenger_threads[i], NULL);
    }

    return 0;
}