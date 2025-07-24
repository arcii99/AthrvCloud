//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {

    int red, yellow, green; //Traffic light variables
    int trafficLight = 0; //0: Red 1: Green
    srand(time(0)); //Seed the random number generator
    
    bool isRaining = false; //Change to true if it is raining
    bool isMorning = true; //Change to false if it is night
    
    //Check if it is morning or night
    if (!isMorning) {
        printf("Good evening, welcome to the Traffic Light Controller!\n");
    } else {
        printf("Good morning, welcome to the Traffic Light Controller!\n");
    }
    
    //Check if it is raining
    if (isRaining) {
        printf("It is raining, drive safe!\n");
    }
    
    //Main loop for traffic light
    while (true) {
        
        //Randomly generate traffic light colors
        red = (rand() % 5) + 1;
        yellow = (rand() % 3) + 1;
        green = (rand() % 5) + 1;
        
        //Display traffic light colors
        printf("Red: %d sec | Yellow: %d sec | Green: %d sec\n", red, yellow, green);
        
        //Change traffic light colors
        if (trafficLight == 0) {
            printf("Traffic light is currently RED\n"); 
            sleep(red); //Delay for red light
            trafficLight = 1; //Change to green light
        } else {
            printf("Traffic light is currently GREEN\n");
            sleep(green); //Delay for green light
            trafficLight = 0; //Change to red light
        }
        
        //Display transition from red to green light and vice versa
        printf("Traffic light is now transitioning to the %s light!\n", (trafficLight == 0) ? "RED" : "GREEN");
        sleep(yellow); //Delay for yellow light
        
    }
    
    return 0;
}