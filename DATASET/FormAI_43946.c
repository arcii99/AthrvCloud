//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>
#include<stdbool.h>

//declare variables
int currentFloor = 1;
int requestedFloor = 0;

//thread synchronization initialization
pthread_mutex_t lockElevator = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conditionElevator = PTHREAD_COND_INITIALIZER;

pthread_mutex_t lockRequest = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conditionRequest = PTHREAD_COND_INITIALIZER;

bool isElevatorDoorOpen = false;
bool isElevatorMoving = false;
bool isElevatorFull = false;

//function to generate random floor requests
int generateFloorRequest(){
    srand(time(NULL));
    int randomFloor = rand()%10 + 1;
    return randomFloor;
}

//function to simulate elevator movement
void* moveElevator(void* arg){
    int targetFloor = *(int*)arg;
    while(currentFloor != targetFloor){
        sleep(1); //simulate elevator travelling between floors
        if(currentFloor < targetFloor){
            currentFloor++;
            printf("Elevator is moving up. Current floor %d\n", currentFloor);
        }else{
            currentFloor--;
            printf("Elevator is moving down. Current floor %d\n", currentFloor);
        }
    }
    isElevatorMoving = false;
    isElevatorDoorOpen = true;
    printf("Elevator has arrived at floor %d. Door is open\n", currentFloor);
    pthread_cond_signal(&conditionElevator); //signal waiting threads
    pthread_exit(NULL);
}

//function to simulate passenger request
void* passengerRequest(void* arg){
    sleep(3); //simulate time for passenger to request elevator
    requestedFloor = generateFloorRequest(); //generate random floor request
    pthread_mutex_lock(&lockElevator); //acquire mutex lock
    while(isElevatorMoving){ //wait until elevator stops moving
        pthread_cond_wait(&conditionElevator, &lockElevator);
    }
    isElevatorFull = true;
    printf("New passenger is requesting floor %d\n", requestedFloor);
    pthread_cond_signal(&conditionRequest); //signal elevator
    pthread_mutex_unlock(&lockElevator); //release mutex lock
    pthread_exit(NULL);
}

//function to handle elevator request
void* processRequest(void* arg){
    while(true){
        pthread_mutex_lock(&lockRequest); //acquire mutex lock
        while(!isElevatorFull){ //wait until elevator is full
            pthread_cond_wait(&conditionRequest, &lockRequest);
        }
        isElevatorFull = false;
        printf("Processing request to floor %d\n", requestedFloor);
        isElevatorMoving = true; //simulate elevator moving
        pthread_mutex_unlock(&lockRequest); //release mutex lock
        pthread_t elevator;
        pthread_create(&elevator, NULL, moveElevator, (void*)&requestedFloor); //create elevator thread
        while(isElevatorDoorOpen){ //wait until elevator door is closed
            sleep(1);
        }
    }
    pthread_exit(NULL);
}

//main function
int main(){
    pthread_t elevatorRequest;
    pthread_t passenger1;

    //create threads
    pthread_create(&elevatorRequest, NULL, processRequest, NULL);
    pthread_create(&passenger1, NULL, passengerRequest, NULL);

    //wait for threads to finish
    pthread_join(elevatorRequest, NULL);
    pthread_join(passenger1, NULL);

    //destroy mutex locks and conditions
    pthread_mutex_destroy(&lockElevator);
    pthread_cond_destroy(&conditionElevator);
    pthread_mutex_destroy(&lockRequest);
    pthread_cond_destroy(&conditionRequest);

    return 0;
}