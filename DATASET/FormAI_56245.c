//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

//Function to simulate delay
void delay(unsigned int milliseconds) {
    usleep(milliseconds * 1000);
}

//Function to print the current state of the traffic lights
void printState(int currentLight) {
    if (currentLight == RED_LIGHT) {
        printf("RED\n");
    } else if (currentLight == YELLOW_LIGHT) {
        printf("YELLOW\n");
    } else if (currentLight == GREEN_LIGHT) {
        printf("GREEN\n");
    }
}

int main() {
    srand(time(NULL)); //Use current time as seed for random number generator

    int currentLight = RED_LIGHT; //Start with red light
    int countdown = 10; //Each light will stay on for 10 seconds

    while (1) { //Infinite loop
        
        //Print the current state of the traffic lights
        printf("Current traffic light state: ");
        printState(currentLight);

        //Decrease the countdown for the current light
        countdown--;

        //If the countdown reaches zero, switch to the next light
        if (countdown == 0) {
            if (currentLight == RED_LIGHT) {
                currentLight = GREEN_LIGHT;
                countdown = 10;
            } else if (currentLight == YELLOW_LIGHT) {
                currentLight = RED_LIGHT;
                countdown = 10;
            } else if (currentLight == GREEN_LIGHT) {
                currentLight = YELLOW_LIGHT;
                countdown = 5;
            }
        }

        //Wait for 1 second before checking again
        delay(1000); 
        
        //Randomly simulate a car arriving at the intersection and waiting for the light to change
        int carWaiting = rand() % 2; //Randomly generates 0 or 1
        if(carWaiting){
            printf("Car waiting at intersection.\n");
        }
    }
    return 0;
}