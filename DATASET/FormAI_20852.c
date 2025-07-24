//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

int main(){
    int crossRoads[5][5] = {0};
    int carsCount[5] = {0};
    int minutes = 0;
    int totalCarsPassed = 0;
    int greenLightDuration = 120;  //in seconds
    int redLightDuration = 60;     //in seconds
    int maxCarSpeed = 50;          //in km/hr
    int i, j;
    srand(time(NULL));     //Initialize rand()
    while (minutes != 30){  //Loop for 30 minutes
        int maxNoOfCars = rand() % 50 + 1;  //Generate random number of cars
        for (i = 1; i <= maxNoOfCars; i++){    //Generate cars
            int direction = rand() % 4 + 1;    //Generate the direction of car
            int speed = rand() % maxCarSpeed + 1;   //Generate random speed
            int lane = rand() % 2 + 1;      //Generate lane
            int position = rand() % 20 + 1; //Generate random position
            if (direction == NORTH || direction == SOUTH){   //If direction is North or South
                if (lane == 1){     //If car is on lane 1
                    if (crossRoads[1][position] == 0){     //Check if the lane is empty
                        crossRoads[1][position] = speed;   //Assign the car's speed to the position
                        carsCount[NORTH]++;    //Increment the number of cars on North direction
                        totalCarsPassed++;     //Increment the total number of cars passed
                    }
                }    
                else{   //If car is on lane 2
                    if (crossRoads[5][position] == 0){     //Check if the lane is empty
                        crossRoads[5][position] = speed;   //Assign the car's speed to the position
                        carsCount[SOUTH]++;    //Increment the number of cars on South direction
                        totalCarsPassed++;     //Increment the total number of cars passed
                    }
                }
            }
            else{   //If direction is East or West
                if (lane == 1){     //If car is on lane 1
                    if (crossRoads[position][5] == 0){     //Check if the lane is empty
                        crossRoads[position][5] = speed;   //Assign the car's speed to the position
                        carsCount[EAST]++;     //Increment the number of cars on East direction
                        totalCarsPassed++;     //Increment the total number of cars passed
                    }
                }    
                else{   //If car is on lane 2
                    if (crossRoads[position][1] == 0){     //Check if the lane is empty
                        crossRoads[position][1] = speed;   //Assign the car's speed to the position
                        carsCount[WEST]++;     //Increment the number of cars on West direction
                        totalCarsPassed++;     //Increment the total number of cars passed
                    }
                }
            }
        }
        for (i = 1; i <= 4; i++){   //Loop for each direction's traffic light
            if (i == NORTH){    //For North Direction
                if (minutes % 2 == 0){  //For green light
                    printf("North Direction: Green Light. Duration: %d seconds.\n", greenLightDuration);
                    for (j = 1; j <= greenLightDuration; j++){
                        int k;
                        for (k = 1; k <= 20; k++){  //Loop for each position in Lane 1
                            if (crossRoads[1][k] != 0){ //If there is a car in the position
                                if (crossRoads[1][k] <= 5){ //Check if the car can move
                                    crossRoads[1][k] = 0;   //Remove the car from the position
                                }
                                else{
                                    crossRoads[1][k] -= 5;  //Reduce the speed of the car by 5km/hr
                                }
                            }
                            if (crossRoads[2][k] != 0){ //If there is a car in the position
                                if (crossRoads[2][k] <= 5){ //Check if the car can move
                                    crossRoads[2][k] = 0;   //Remove the car from the position
                                    printf("Car passed the crossing.\n");
                                }
                                else{
                                    crossRoads[2][k] -= 5;  //Reduce the speed of the car by 5km/hr
                                }
                            }
                        }
                    }
                }
                else{   //For red light
                    printf("North Direction: Red Light. Duration: %d seconds.\n", redLightDuration);
                    for (j = 1; j <= redLightDuration; j++){
                        int k;
                        for (k = 1; k <= 20; k++){  //Loop for each position in Lane 1
                            if (crossRoads[1][k] != 0){     //If there is a car in the position
                                if (crossRoads[1][k] <= 5){     //Check if the car can move
                                    crossRoads[1][k] = 0;     //Remove the car from the position
                                }
                                else{
                                    crossRoads[1][k] -= 5;    //Reduce the speed of the car by 5km/hr
                                }
                            }
                            if (crossRoads[2][k] != 0){     //If there is a car in the position
                                if (crossRoads[2][k] <= 5){     //Check if the car can move
                                    crossRoads[2][k] = 0;     //Remove the car from the position
                                    printf("Car passed the crossing.\n");
                                }
                                else{
                                    crossRoads[2][k] -= 5;    //Reduce the speed of the car by 5km/hr
                                }
                            }
                        }
                    }
                }
            }
            else if (i == SOUTH){   //For South Direction
                if (minutes % 2 == 0){  //For green light
                    printf("South Direction: Green Light. Duration: %d seconds.\n", greenLightDuration);
                    for (j = 1; j <= greenLightDuration; j++){
                        int k;
                        for (k = 1; k <= 20; k++){  //Loop for each position in Lane 1
                            if (crossRoads[5][k] != 0){ //If there is a car in the position
                                if (crossRoads[5][k] <= 5){ //Check if the car can move
                                    crossRoads[5][k] = 0;   //Remove the car from the position
                                }
                                else{
                                    crossRoads[5][k] -= 5;  //Reduce the speed of the car by 5km/hr
                                }
                            }
                            if (crossRoads[4][k] != 0){ //If there is a car in the position
                                if (crossRoads[4][k] <= 5){ //Check if the car can move
                                    crossRoads[4][k] = 0;   //Remove the car from the position
                                    printf("Car passed the crossing.\n");
                                }
                                else{
                                    crossRoads[4][k] -= 5;  //Reduce the speed of the car by 5km/hr
                                }
                            }
                        }
                    }
                }
                else{   //For red light
                    printf("South Direction: Red Light. Duration: %d seconds.\n", redLightDuration);
                    for (j = 1; j <= redLightDuration; j++){
                        int k;
                        for (k = 1; k <= 20; k++){  //Loop for each position in Lane 1
                            if (crossRoads[5][k] != 0){     //If there is a car in the position
                                if (crossRoads[5][k] <= 5){     //Check if the car can move
                                    crossRoads[5][k] = 0;     //Remove the car from the position
                                }
                                else{
                                    crossRoads[5][k] -= 5;    //Reduce the speed of the car by 5km/hr
                                }
                            }
                            if (crossRoads[4][k] != 0){     //If there is a car in the position
                                if (crossRoads[4][k] <= 5){     //Check if the car can move
                                    crossRoads[4][k] = 0;     //Remove the car from the position
                                    printf("Car passed the crossing.\n");
                                }
                                else{
                                    crossRoads[4][k] -= 5;    //Reduce the speed of the car by 5km/hr
                                }
                            }
                        }
                    }
                }
            }
            else if (i == EAST){    //For East Direction
                if (minutes % 2 == 0){  //For green light
                    printf("East Direction: Green Light. Duration: %d seconds.\n", greenLightDuration);
                    for (j = 1; j <= greenLightDuration; j++){
                        int k;
                        for (k = 1; k <= 20; k++){  //Loop for each position in Lane 1
                            if (crossRoads[k][5] != 0){ //If there is a car in the position
                                if (crossRoads[k][5] <= 5){ //Check if the car can move
                                    crossRoads[k][5] = 0;   //Remove the car from the position
                                }
                                else{
                                    crossRoads[k][5] -= 5;  //Reduce the speed of the car by 5km/hr
                                }
                            }
                            if (crossRoads[k][4] != 0){ //If there is a car in the position
                                if (crossRoads[k][4] <= 5){ //Check if the car can move
                                    crossRoads[k][4] = 0;   //Remove the car from the position
                                    printf("Car passed the crossing.\n");
                                }
                                else{
                                    crossRoads[k][4] -= 5;  //Reduce the speed of the car by 5km/hr
                                }
                            }
                        }
                    }
                }
                else{   //For red light
                    printf("East Direction: Red Light. Duration: %d seconds.\n", redLightDuration);
                    for (j = 1; j <= redLightDuration; j++){
                        int k;
                        for (k = 1; k <= 20; k++){  //Loop for each position in Lane 1
                            if (crossRoads[k][5] != 0){     //If there is a car in the position
                                if (crossRoads[k][5] <= 5){     //Check if the car can move
                                    crossRoads[k][5] = 0;     //Remove the car from the position
                                }
                                else{
                                    crossRoads[k][5] -= 5;    //Reduce the speed of the car by 5km/hr
                                }
                            }
                            if (crossRoads[k][4] != 0){     //If there is a car in the position
                                if (crossRoads[k][4] <= 5){     //Check if the car can move
                                    crossRoads[k][4] = 0;     //Remove the car from the position
                                    printf("Car passed the crossing.\n");
                                }
                                else{
                                    crossRoads[k][4] -= 5;    //Reduce the speed of the car by 5km/hr
                                }
                            }
                        }
                    }
                }
            }
            else{   //For West Direction
                if (minutes % 2 == 0){  //For green light
                    printf("West Direction: Green Light. Duration: %d seconds.\n", greenLightDuration);
                    for (j = 1; j <= greenLightDuration; j++){
                        int k;
                        for (k = 1; k <= 20; k++){  //Loop for each position in Lane 1
                            if (crossRoads[k][1] != 0){ //If there is a car in the position
                                if (crossRoads[k][1] <= 5){ //Check if the car can move
                                    crossRoads[k][1] = 0;   //Remove the car from the position
                                }
                                else{
                                    crossRoads[k][1] -= 5;  //Reduce the speed of the car by 5km/hr
                                }
                            }
                            if (crossRoads[k][2] != 0){ //If there is a car in the position
                                if (crossRoads[k][2] <= 5){ //Check if the car can move
                                    crossRoads[k][2] = 0;   //Remove the car from the position
                                    printf("Car passed the crossing.\n");
                                }
                                else{
                                    crossRoads[k][2] -= 5;  //Reduce the speed of the car by 5km/hr
                                }
                            }
                        }
                    }
                }
                else{   //For red light
                    printf("West Direction: Red Light. Duration: %d seconds.\n", redLightDuration);
                    for (j = 1; j <= redLightDuration; j++){
                        int k;
                        for (k = 1; k <= 20; k++){  //Loop for each position in Lane 1
                            if (crossRoads[k][1] != 0){     //If there is a car in the position
                                if (crossRoads[k][1] <= 5){     //Check if the car can move
                                    crossRoads[k][1] = 0;     //Remove the car from the position
                                }
                                else{
                                    crossRoads[k][1] -= 5;    //Reduce the speed of the car by 5km/hr
                                }
                            }
                            if (crossRoads[k][2] != 0){     //If there is a car in the position
                                if (crossRoads[k][2] <= 5){     //Check if the car can move
                                    crossRoads[k][2] = 0;     //Remove the car from the position
                                    printf("Car passed the crossing.\n");
                                }
                                else{
                                    crossRoads[k][2] -= 5;    //Reduce the speed of the car by 5km/hr
                                }
                            }
                        }
                    }
                }
            }
        }
        for (i = 1; i <= 4; i++){   //Print the number of cars on each direction
            if (i == NORTH){
                printf("Number of cars on North direction: %d\n", carsCount[NORTH]);
            }
            else if (i == SOUTH){
                printf("Number of cars on South direction: %d\n", carsCount[SOUTH]);
            }
            else if (i == EAST){
                printf("Number of cars on East direction: %d\n", carsCount[EAST]);
            }
            else{
                printf("Number of cars on West direction: %d\n", carsCount[WEST]);
            }
        }
        printf("Total number of cars passed in %d minutes: %d\n", minutes+1, totalCarsPassed);   //Print the total number of cars passed in each minute
        minutes++;  //Increment minutes
    }
    return 0;
}