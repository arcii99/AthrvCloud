//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define MAX 10

//Elevator struct to hold elevator's current status
struct elevator {
    int current_floor;
    int direction; //1 for up, -1 for down
    int num_people;
} e1;

pthread_mutex_t elevator_mutex = PTHREAD_MUTEX_INITIALIZER; //Mutex for elevator access
pthread_cond_t elevator_cond = PTHREAD_COND_INITIALIZER; //Condition variable for elevator waiting

//Function to simulate person going to elevator and pressing the button
void person() {
    int dest_floor = rand() % MAX + 1;
    int wait_time = rand() % 10 + 1;
    printf("Person going to floor %d, waiting for %d seconds\n", dest_floor, wait_time);
    sleep(wait_time);
    pthread_mutex_lock(&elevator_mutex); //Lock elevator mutex
    while(e1.current_floor != dest_floor || e1.num_people >= 5 || (dest_floor > e1.current_floor && e1.direction == -1) || (dest_floor < e1.current_floor && e1.direction == 1)) {
        pthread_cond_wait(&elevator_cond, &elevator_mutex); //Wait for elevator to arrive or be able to accommodate more people
    }
    e1.num_people++; //Person enters elevator
    printf("Person entered elevator at floor %d, going to floor %d\n", e1.current_floor, dest_floor);
    pthread_mutex_unlock(&elevator_mutex);
}

//Function to simulate elevator movement
void *elevator() {
    while(1) {
        pthread_mutex_lock(&elevator_mutex); //Lock elevator mutex
        if(e1.num_people == 0) { //If elevator is empty, wait for signal
            printf("Elevator waiting for signal\n");
            pthread_cond_wait(&elevator_cond, &elevator_mutex);
        }
        printf("Elevator moving %s from floor %d\n", e1.direction == 1 ? "up" : "down", e1.current_floor);
        e1.current_floor += e1.direction; //Change floor based on direction
        if(e1.current_floor == MAX) { //If elevator reaches top floor, change direction
            e1.direction = -1;
        }
        else if(e1.current_floor == 1) { //If elevator reaches bottom floor, change direction
            e1.direction = 1;
        }
        pthread_mutex_unlock(&elevator_mutex);
        sleep(2); //Wait for elevator to reach next floor
    }
}

int main() {
    pthread_t elevator_thread;
    pthread_create(&elevator_thread, NULL, elevator, NULL); //Start elevator thread
    srand(time(NULL));
    while(1) { //Infinitely cycle through simulating people
        person();
        pthread_mutex_lock(&elevator_mutex); //Lock elevator mutex
        e1.num_people--; //Person exits elevator
        printf("Person exited elevator at floor %d\n", e1.current_floor);
        pthread_cond_signal(&elevator_cond); //Signal elevator to continue
        pthread_mutex_unlock(&elevator_mutex);
    }
    pthread_join(elevator_thread, NULL); //Join elevator thread
    return 0;
}