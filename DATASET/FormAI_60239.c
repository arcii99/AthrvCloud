//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

//function declarations
void initializeElevator();
void startElevator();
void stopElevator();
void moveElevator();
void openDoors();
void closeDoors();
void displayElevatorStatus();
void chooseFloor();
void resetElevator();

//variables
int floors[10]; //10 floor building
int currentFloor = 0; //initial floor
int targetFloor;
int direction = 0; //initially the elevator is stationary
bool doorsOpen = false; //doors are initially closed
bool elevatorOn = true; //initial state of the elevator is on
int totalTrips = 0; //total trips made by the elevator
int totalFloorsPassed = 0; //total floors passed by the elevator
float maintenanceCounter = 0.0; //maintenace counter set to 0.0
float maintenanceInterval = 100.0; //maaintenance inteval set to 100


void initializeElevator(){
    printf("\nInitializing elevator...\n");
    //set all floors to 0 initially
    for(int i=0;i<10;i++){
        floors[i]=0;
    }
    printf("Elevator initialized.\n");
}

void startElevator(){
    printf("\nStarting elevator...\n");
    moveElevator();
}

void stopElevator(){
    printf("\nStopping elevator...\n");
    //elevator stops at current floor
    printf("Elevator stopped at floor %d\n",currentFloor);
    openDoors();
}

void moveElevator(){
    printf("\nMoving elevator...\n");
    //generate a random target floor
    srand(time(NULL));
    targetFloor = rand() % 10;
    //set elevator direction based on target floor
    if(targetFloor > currentFloor){
        direction = 1;
    }else if(targetFloor < currentFloor){
        direction = -1;
    }else{
        direction = 0;
    }
    while(currentFloor != targetFloor){
        currentFloor += direction;
        if(floors[currentFloor] == 1){
            stopElevator();
            break;
        }else{
            totalFloorsPassed++;
        }
    }
    if(currentFloor == targetFloor){
        stopElevator();
    }
}

void openDoors(){
    printf("\nOpening doors...\n");
    doorsOpen = true;
    displayElevatorStatus();
    chooseFloor();
}

void closeDoors(){
    printf("\nClosing doors...\n");
    doorsOpen = false;
    if(totalTrips == maintenanceInterval){
        resetElevator();
    }else{
        moveElevator();
    }
}

void displayElevatorStatus(){
    printf("\nElevator status:\n");
    printf("Current floor: %d\n",currentFloor);
    printf("Doors open: %s\n", doorsOpen ? "True" : "False");
    printf("Total trips: %d\n",totalTrips);
    printf("Total floors passed: %d\n",totalFloorsPassed);
    printf("Maintenance counter: %.2f%%\n",maintenanceCounter);
}

void chooseFloor(){
    printf("\nPlease choose a floor from 0 to 9: ");
    int chosenFloor;
    scanf("%d",&chosenFloor);
    if(chosenFloor == currentFloor){
        printf("\nYou are already on floor %d!",currentFloor);
        chooseFloor();
    }else if(chosenFloor < 0 || chosenFloor > 9){
        printf("\nInvalid floor number!");
        chooseFloor();
    }else{
        floors[chosenFloor] = 1;
        totalTrips++;
        printf("\nFloor %d selected.",chosenFloor);
        closeDoors();
    }
}

void resetElevator(){
    printf("\nPerforming maintenance...\n");
    //set all floors to 0 initially
    for(int i=0;i<10;i++){
        floors[i]=0;
    }
    currentFloor = 0;
    direction = 0;
    doorsOpen = false;
    totalTrips = 0;
    totalFloorsPassed = 0;
    maintenanceCounter = 0.0;
    printf("Elevator reset.\n");
    startElevator();
}

int main(){
    initializeElevator();
    while(elevatorOn){
        startElevator();
        if(totalTrips == maintenanceInterval){
            maintenanceCounter = 100.0;
        }else{
            maintenanceCounter = (totalTrips/maintenanceInterval)*100;
        }
    }
    return 0;
}