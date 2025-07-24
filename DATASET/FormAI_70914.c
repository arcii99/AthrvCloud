//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int curr_floor = 1; // Initial position of elevator
int dest_floor = -1; // Assume no destination set at the beginning
int num_people = 0; // Number of people currently in elevator
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for thread safety
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; // Conditional variable for signaling

void *elevator(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        while(dest_floor == -1) { // Wait for someone to set a destination
            pthread_cond_wait(&cond, &mutex);
        }

        if(dest_floor > curr_floor) { // Going up
            printf("Elevator going up from floor %d to floor %d\n", curr_floor, dest_floor);
            while(curr_floor < dest_floor) {
                sleep(1); // Simulate time taken in elevator ride
                curr_floor++;
            }
        } else { // Going down
            printf("Elevator going down from floor %d to floor %d\n", curr_floor, dest_floor);
            while(curr_floor > dest_floor) {
                sleep(1); // Simulate time taken in elevator ride
                curr_floor--;
            }
        }

        printf("Elevator arrived at floor %d\n", curr_floor);
        dest_floor = -1;
        num_people = 0;
        pthread_cond_signal(&cond); // Signal that elevator is available
        pthread_mutex_unlock(&mutex);
    }
}

void *person(void *arg) {
    int floor = *(int*)arg;
    int dest = rand() % 10 + 1; // Choose a random destination floor
    printf("Person on floor %d pressed button for floor %d\n", floor, dest);

    pthread_mutex_lock(&mutex);
    while(dest_floor != -1 && dest_floor != curr_floor) { // Wait for elevator to become available
        pthread_cond_wait(&cond, &mutex);
    }

    if(dest_floor == -1) { // Set destination of elevator
        dest_floor = dest;
    }

    num_people++; // Add person to elevator
    printf("Person on floor %d entered elevator\n", floor);
    pthread_cond_signal(&cond); // Signal that elevator has a new passenger
    pthread_mutex_unlock(&mutex);

    while(curr_floor != dest) { // Wait for elevator to reach destination floor
        sleep(1);
    }

    printf("Person reached destination floor %d\n", dest);
    pthread_mutex_lock(&mutex);
    num_people--; // Remove person from elevator
    if(num_people == 0) { // If no one left in elevator, signal that elevator is available
        pthread_cond_signal(&cond);
    }
    pthread_mutex_unlock(&mutex);
}

int main() {
    srand(time(NULL));
    pthread_t tid_elevator, tid_person[20];

    pthread_create(&tid_elevator, NULL, elevator, NULL); // Create elevator thread
    sleep(1); // Wait for elevator thread to start

    int i, floors[20];
    for(i=0; i<20; i++) {
        floors[i] = rand() % 10 + 1; // Choose a random current floor for each person
        pthread_create(&tid_person[i], NULL, person, &floors[i]); // Create person threads
        sleep(1); // Wait for person threads to start
    }

    for(i=0; i<20; i++) {
        pthread_join(tid_person[i], NULL); // Wait for all person threads to finish
    }
    pthread_cancel(tid_elevator); // Terminate elevator thread
    pthread_join(tid_elevator, NULL); // Wait for elevator thread to finish

    return 0;
}