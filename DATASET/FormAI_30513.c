//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

// Global Variables
int elevator_floor=0; // Current floor of the elevator
int direction=1; // 1 for upward, -1 for downward
pthread_mutex_t lock; // Mutex lock for synchronization
int num_people=0; // number of people currently inside the elevator

// Function to simulate the movement of elevator
void move_elevator(){
    printf("Elevator moving from floor %d ", elevator_floor);
    if (direction==1){
        printf("upward\n");
        elevator_floor++;
    }
    else{
        printf("downward\n");
        elevator_floor--;
    }
}

// Function to simulate the people entering elevator
void enter_elevator(int num){
    if (num+num_people<=10){
        num_people+=num;
        printf("%d people enter the elevator. Total people inside: %d\n", num, num_people);
    }
    else{
        printf("Elevator overloaded. Wait for next elevator\n");
    }
}

// Function to simulate the people leaving elevator
void leave_elevator(int num){
    num_people-=num;
    printf("%d people leave the elevator. Total people inside: %d\n", num, num_people);
}

// Function to simulate the elevator operation
void *operate_elevator(void *arg){
    while (1){
        pthread_mutex_lock(&lock);
        if (elevator_floor==0 || elevator_floor==10){
            direction*=-1; // Change direction
        }
        move_elevator();
        if (elevator_floor==5){
            enter_elevator(6);
        }
        else if (elevator_floor==8){
            leave_elevator(3);
        }
        pthread_mutex_unlock(&lock);
        sleep(2); // wait for 2 seconds
    }
}

int main(){
    pthread_t elevator_thread;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&elevator_thread, NULL, operate_elevator, NULL);
    while (1){
        // main program loop
        // can have code for requesting elevator from a floor
    }
    pthread_join(elevator_thread, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}