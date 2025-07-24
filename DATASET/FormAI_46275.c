//FormAI DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Method that handles robot movement based on commands
void moveRobot(char command){
    switch(command){
        case 'U':
            printf("Moving robot up...\n");
            break;
        case 'D':
            printf("Moving robot down...\n");
            break;
        case 'L':
            printf("Moving robot left...\n");
            break;
        case 'R':
            printf("Moving robot right...\n");
            break;
        default:
            printf("Invalid command!\n");
            break;
    }
    sleep(1); // Wait for 1 second before executing next command
}

// Method that reads commands from input
void* readInput(void* arg){
    char command;
    while(1){
        printf("Enter a command (U/D/L/R): ");
        scanf(" %c", &command);
        moveRobot(command);
    }
}

// Main method
int main(){
    pthread_t inputThread;
    pthread_create(&inputThread, NULL, readInput, NULL);

    pthread_join(inputThread, NULL); // Wait for input thread to finish
    return 0;
}