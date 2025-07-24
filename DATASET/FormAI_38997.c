//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<signal.h>

// Declare Functions
void stopHandler(int sig);
void proceedHandler(int sig);

// Declare Global Variables
int proceedFlag = 0;
int stopFlag = 0;
char lightColor[10];

int main(){
    // Set seed for random number generator
    srand(time(NULL));

    // Register signal handlers
    signal(SIGINT, stopHandler);
    signal(SIGQUIT, proceedHandler);

    // Infinite loop for traffic light controller
    while(1){
        // Randomize traffic light colors
        int randNum = rand() % 3;
        if(randNum == 0){
            sprintf(lightColor, "RED");
        }
        else if(randNum == 1){
            sprintf(lightColor, "YELLOW");
        }
        else{
            sprintf(lightColor, "GREEN");
        }
        printf("\nTraffic Light: %s\n", lightColor);

        // Check for signal flag to determine action
        if(stopFlag == 1){
            printf("\nSTOP! Proceed when signal received.\n");
            proceedFlag = 0;
        }
        else if(proceedFlag == 1){
            printf("\nProceed with caution.\n");
            stopFlag = 0;
        }
        else{
            printf("\nWaiting for signal...\n");
        }

        // Sleep for 3 seconds before repeating loop
        sleep(3);
    }

    return 0;
}

// Signal Handler Functions
void stopHandler(int sig){
    if(sig == SIGINT){
        stopFlag = 1;
        proceedFlag = 0;
        printf("\nStop signal received.\n");
    }
}

void proceedHandler(int sig){
    if(sig == SIGQUIT){
        proceedFlag = 1;
        stopFlag = 0;
        printf("\nProceed signal received.\n");
    }
}