//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int floor = 0; //initial floor of elevator
int numPeople = 0; //number of people in elevator

//function to print current floor and number of people in elevator
void printStatus(){
    printf("Elevator is at floor %d with %d people\n", floor, numPeople);
}

//function to simulate elevator movement
void goToFloor(int destFloor){
    if(destFloor == floor){
        printf("Elevator is already on this floor\n");
    }
    else{
        printf("Elevator is going to floor %d\n", destFloor);
        //simulating elevator movement
        while(destFloor != floor){
            if(destFloor > floor){
                floor++;
            }
            else{
                floor--;
            }
            //printing current status after each movement
            printStatus();
            usleep(500000); //sleep for 0.5 seconds to make it realistic
        }
        printf("Elevator has arrived at floor %d\n", floor);
    }
}

//function to simulate people entering elevator
void enterElevator(int numPeopleEntered){
    printf("%d people entered the elevator\n", numPeopleEntered);
    numPeople += numPeopleEntered;
    printStatus();
}

//function to simulate people exiting elevator
void exitElevator(int numPeopleExited){
    if(numPeopleExited > numPeople){
        printf("Error: Number of people exiting is greater than number of people in elevator\n");
    }
    else{
        printf("%d people exited the elevator\n", numPeopleExited);
        numPeople -= numPeopleExited;
        printStatus();
    }
}

int main(){
    printf("Welcome to the Medieval Elevator Simulation\n");
    
    //simulating elevator movement to floor 1
    goToFloor(1);
    
    //people entering elevator
    enterElevator(3);
    
    //simulating elevator movement to floor 4
    goToFloor(4);
    
    //people exiting elevator
    exitElevator(1);
    
    //simulating elevator movement to floor 2
    goToFloor(2);
    
    //people entering elevator
    enterElevator(2);
    
    //simulating elevator movement to floor 5
    goToFloor(5);
    
    //people exiting elevator
    exitElevator(2);
    
    printf("Thank you for using the Medieval Elevator Simulation\n");
    
    return 0;
}