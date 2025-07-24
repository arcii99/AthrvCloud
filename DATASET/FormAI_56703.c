//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defining Constants
#define MAX_TIME 1000
#define MAX_CARS 100
#define MAX_DELAY 10

//Structure for Cars
typedef struct{
    int id;
    int speed;
    int position;
}Car;

//Function to generate random number 
int randomNumber(int minimum, int maximum){
    int range = maximum - minimum + 1; 
    int randomNum = rand() % range + minimum;
    return randomNum;
}

int main(){
    srand(time(0)); //To generate random numbers

    //Initializing Cars
    Car cars[MAX_CARS]; 
    int numOfCars = randomNumber(0, MAX_CARS); //Generating random number of cars
    for(int i = 0; i < numOfCars; i++){
        cars[i].id = i+1; 
        cars[i].speed = randomNumber(30, 80); //Assigning random speed to each car
        cars[i].position = 0; //Starts at position 0
    }

    //Traffic Flow Simulation
    for(int t = 1; t <=MAX_TIME; t++){
        //Printing Current Time and Car Positions
        printf("Time: %d\n", t);
        for(int i = 0; i < numOfCars; i++){
            printf("Car %d Position: %d\n", cars[i].id, cars[i].position);
        }
        
        //Moving Cars
        for(int i = 0; i < numOfCars; i++){
            int delay = randomNumber(0, MAX_DELAY); //Delay for each car
            if(delay == 0){ //If delay is 0, then no delay
                cars[i].position += cars[i].speed; //Moving car based on its speed
            }
        }
    }
    
    return 0;
}