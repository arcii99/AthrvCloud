//FormAI DATASET v1.0 Category: Smart home light control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to turn on the lights
void turnOnLights(int *lightStatus) {
    printf("Turning on the lights...\n");
    *lightStatus = 1; //set light status to on
    printf("Lights are now on.\n");
}

//function to turn off the lights
void turnOffLights(int *lightStatus) {
    printf("Turning off the lights...\n");
    *lightStatus = 0; //set light status to off
    printf("Lights are now off.\n");
}

//function to randomly turn on/off the lights
void randomizeLights(int *lightStatus) {
    int randNum = rand() % 2; //generate a random number between 0 and 1
    if(randNum == 0) {
        turnOffLights(lightStatus);
    } else {
        turnOnLights(lightStatus);
    }
}

int main() {
    int lightStatus = 0; //initialize the light status to off
    srand(time(0)); //seed the random number generator with the time
 
    printf("Welcome to Paranoid Smart Home Light Control System.\n");
    printf("Initializing system...\n");
    //simulate initializing the system by waiting a random amount of time
    int initTime = rand() % 10 + 1; //generate a random number between 1 and 10
    printf("System initialized in %d seconds.\n", initTime);
    printf("System is now running.\n");
 
    //infinite loop to simulate the system running indefinitely
    while(1) {
        //wait a random amount of time before doing anything
        int waitTime = rand() % 10 + 1; //generate a random number between 1 and 10
        printf("Waiting for %d seconds...\n", waitTime);
        sleep(waitTime);
 
        //randomly decide whether to turn on/off the lights
        randomizeLights(&lightStatus);
 
        //if the lights have been turned on, wait a random amount of time before turning them off again
        if(lightStatus == 1) {
            int onTime = rand() % 10 + 1; //generate a random number between 1 and 10
            printf("Lights are on. Waiting for %d seconds...\n", onTime);
            sleep(onTime);
            turnOffLights(&lightStatus);
        }
    }
 
    return 0;
}