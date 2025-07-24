//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int redLightTime = 20, yellowLightTime = 3, greenLightTime = 15; // Initializing time for red, yellow and green lights respectively.

    time_t startTime, currentTime; // Using time_t datatype to store start time of the program and current time.

    startTime = time(NULL);  // Starting time when program starts running

     while(1){ // Runs infinitely until program is closed.

        currentTime = time(NULL); // Takes current time.

        if(currentTime - startTime >= redLightTime){ //Checking if red light time is ended.
            printf("RED LIGHT ON!!!\n"); // If red light time is ended, the print out the text.
            startTime = time(NULL); // Resets start time for next light.
            continue; // skip to the next iteration of the loop.
        }

        if(currentTime - startTime >= yellowLightTime){ //Checking if yellow light time is ended.
            printf("YELLOW LIGHT ON!!!\n"); // If yellow light time is ended, print out the text.
            startTime = time(NULL); // Resets start time for next light.
            continue; // skip to the next iteration of the loop.
        }

        if(currentTime - startTime >= greenLightTime){ //Checking if green light time is ended.
            printf("GREEN LIGHT ON!!!\n"); // If green light time is ended, print out the text.
            startTime = time(NULL); // Resets start time for next light.
            continue; // skip to the next iteration of the loop.
        }
    }

    return 0;
}