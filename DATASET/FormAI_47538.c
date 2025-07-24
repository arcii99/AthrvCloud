//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

// Define functions
void printMenu();
void takeOff();
void land();
void droneInfo();
void batteryLife();
void cameraOn();
void cameraOff();
void moveUp();
void moveDown();
void moveLeft();
void moveRight();

int main() {
    int isFlying = 0;
    int battery = 100;

    // Welcome message
    printf("Welcome to the Retro Drone Remote Control!\n");
    
    // Loop until user exits
    while(1) {
        printMenu();
        char command[MAX_COMMAND_LENGTH];
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove newline character from input
        command[strcspn(command, "\n")] = 0;

        // Check for command
        if(strcmp(command, "takeoff") == 0) {
            if(isFlying) {
                printf("Drone is already in the air!\n");
            } else {
                takeOff();
                isFlying = 1;
            }
        } else if(strcmp(command, "land") == 0) {
            if(!isFlying) {
                printf("Drone is already on the ground!\n");
            } else {
                land();
                isFlying = 0;
            }
        } else if(strcmp(command, "droneinfo") == 0) {
            droneInfo();
        } else if(strcmp(command, "batterylife") == 0) {
            batteryLife();
        } else if(strcmp(command, "cameraon") == 0) {
            cameraOn();
        } else if(strcmp(command, "cameraoff") == 0) {
            cameraOff();
        } else if(strcmp(command, "moveup") == 0) {
            moveUp();
        } else if(strcmp(command, "movedown") == 0) {
            moveDown();
        } else if(strcmp(command, "moveleft") == 0) {
            moveLeft();
        } else if(strcmp(command, "moveright") == 0) {
            moveRight();
        } else if(strcmp(command, "exit") == 0) {
            printf("Exiting Retro Drone Remote Control...\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }

    // Exit program
    return 0;
}

void printMenu() {
    printf("=======================================\n");
    printf("| Retro Drone Remote Control (v1.0)   |\n");
    printf("|-------------------------------------|\n");
    printf("| Available commands:                 |\n");
    printf("| - takeoff                            |\n");
    printf("| - land                               |\n");
    printf("| - droneinfo                          |\n");
    printf("| - batterylife                        |\n");
    printf("| - cameraon                           |\n");
    printf("| - cameraoff                          |\n");
    printf("| - moveup                             |\n");
    printf("| - movedown                           |\n");
    printf("| - moveleft                           |\n");
    printf("| - moveright                          |\n");
    printf("| - exit                               |\n");
    printf("=======================================\n");
}

void takeOff() {
    printf("Drone is taking off!\n");
}

void land() {
    printf("Drone is landing!\n");
}

void droneInfo() {
    printf("=======================================\n");
    printf("| Drone Information                   |\n");
    printf("|-------------------------------------|\n");
    printf("| Model: Retro Drone 5000              |\n");
    printf("| Max altitude: 100m                  |\n");
    printf("| Max speed: 50km/h                   |\n");
    printf("=======================================\n");
}

void batteryLife() {
    printf("Battery: %d%%\n", rand() % 100);
}

void cameraOn() {
    printf("Camera is on!\n");
}

void cameraOff() {
    printf("Camera is off!\n");
}

void moveUp() {
    printf("Drone is moving up!\n");
}

void moveDown() {
    printf("Drone is moving down!\n");
}

void moveLeft() {
    printf("Drone is moving left!\n");
}

void moveRight() {
    printf("Drone is moving right!\n");
}