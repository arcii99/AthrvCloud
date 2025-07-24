//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define MAX_CAPACITY 20

sem_t elevator;
sem_t rider_mutex;
sem_t space_mutex;

int floor = 1;
int capacity = 0;
int num_of_riders_waiting = 0;
int num_of_riders_completed = 0;
int num_of_riders[MAX_CAPACITY];

void* rider(void* arg) {
    int* id = (int*) arg;

    sem_wait(&rider_mutex); // lock the mutex
    printf("Rider: %d is waiting on floor: %d\n", *id, floor);
    num_of_riders_waiting++; // increase the number of riders waiting
    num_of_riders[num_of_riders_waiting - 1] = *id; // add rider to waiting list
    sem_post(&rider_mutex); // unlock the mutex
    sem_wait(&elevator); // wait for the elevator
    
    sem_wait(&space_mutex); // lock the mutex
    printf("Rider: %d entered elevator on floor: %d\n", *id, floor);
    capacity++; // increase the elevator occupancy
    sem_post(&space_mutex); // unlock the mutex

    sem_wait(&rider_mutex); // lock the mutex
    num_of_riders_waiting--; // decrease the number of riders waiting
    sem_post(&rider_mutex); // unlock the mutex
    
    while (floor != 4) {
        sem_wait(&elevator); // wait for elevator to reach the next floor
    }
    
    sem_wait(&space_mutex); // lock the mutex
    printf("Rider: %d exited elevator on floor: %d\n", *id, floor);
    capacity--; // decrease the elevator occupancy
    sem_post(&space_mutex); // unlock the mutex

    num_of_riders_completed++; // increase the number of completed riders
    sem_post(&elevator); // signal the elevator to continue

    pthread_exit(NULL);
}

void* elevator_man() {
    while (num_of_riders_completed < MAX_CAPACITY) {
        if(capacity == 0 && num_of_riders_waiting > 0){
            sem_wait(&rider_mutex); // lock the mutex
            printf("Elevator is ascending to floor: 2\n");
            floor = 2; // elevator ascends to floor 2
            sem_post(&rider_mutex); // unlock the mutex
        } else if(capacity > 0 && floor != 4){
            sem_wait(&rider_mutex); // lock the mutex
            printf("Elevator is ascending to floor: %d\n", floor+1);
            floor++; // elevator ascends to next floor
            sem_post(&rider_mutex); // unlock the mutex
        } else if(capacity > 0 && floor == 4){
            sem_wait(&rider_mutex); // lock the mutex
            printf("Elevator is descending to floor: 1\n");
            floor = 1; // elevator descends to floor 1
            sem_post(&rider_mutex); // unlock the mutex
        }

        sem_post(&elevator); // signal the elevator has arrived
        usleep(10000); // sleep for 10 millisec (for simulation purpose only)
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t rider_threads[MAX_CAPACITY];
    pthread_t elevator_thread;

    sem_init(&elevator, 0, 0);
    sem_init(&rider_mutex, 0, 1);
    sem_init(&space_mutex, 0, 1);

    for(int i=0; i < MAX_CAPACITY; i++){
        int* arg = malloc(sizeof(*arg));
        *arg = i+1;
        pthread_create(&rider_threads[i], NULL, &rider, arg); // create rider threads
    }

    pthread_create(&elevator_thread, NULL, &elevator_man, NULL); // create elevator thread

    for(int i=0; i < MAX_CAPACITY; i++){
        pthread_join(rider_threads[i], NULL); // wait for all riders to complete
    }

    pthread_join(elevator_thread, NULL); // wait for elevator to complete

    return 0;
}