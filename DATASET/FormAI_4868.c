//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //for sleep
#include <signal.h> //for signal handling

//define states
#define GREEN 1
#define YELLOW 2
#define RED 3

//global variables
int state = GREEN;
int isRunning = 1;

//signal handler function to exit the program
void handleSignal(int signal) {
    printf("\nExiting...\n");
    isRunning = 0;
}

//function to change state
void changeState() {
    switch (state) {
        case GREEN:
            printf("Green -> ");
            state = YELLOW;
            sleep(3);
            break;
        case YELLOW:
            printf("Yellow -> ");
            state = RED;
            sleep(5);
            break;
        case RED:
            printf("Red -> ");
            state = GREEN;
            sleep(10);
            break;
    }
}

int main() {
    //register signal handler
    signal(SIGINT, handleSignal);

    //run the traffic light controller
    while (isRunning) {
        changeState();
    }

    return 0;
}