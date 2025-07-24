//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DRONES 10
#define MAX_COMMAND_LENGTH 100

typedef struct Drone {
    int id;
    bool isFlying;
    int batteryLevel;
    char* currentLocation;
} Drone;

void initializeDrones(Drone drones[MAX_DRONES]) {
    for(int i = 0; i < MAX_DRONES; i++) {
        drones[i].id = i+1;
        drones[i].isFlying = false;
        drones[i].batteryLevel = 100;
        drones[i].currentLocation = "Home base";
    }
}

void displayDrones(Drone drones[MAX_DRONES]) {
    for(int i = 0; i < MAX_DRONES; i++) {
        printf("Drone ID: %d | Battery Level: %d%% | Current Location: %s | Status: %s\n", drones[i].id, drones[i].batteryLevel, drones[i].currentLocation, drones[i].isFlying ? "Flying" : "Landed");
    }
}

void flyDrone(Drone* drone, char* destination) {
    if(drone->isFlying) {
        printf("Drone %d is already flying!\n", drone->id);
    }
    else if(strcmp(drone->currentLocation, destination) == 0) {
        printf("Drone %d is already at %s!\n", drone->id, destination);
    }
    else {
        printf("Drone %d taking off from %s to %s...\n", drone->id, drone->currentLocation, destination);
        drone->isFlying = true;
        drone->batteryLevel -= 20;
        drone->currentLocation = destination;
    }
}

void landDrone(Drone* drone) {
    if(!drone->isFlying) {
        printf("Drone %d is already landed!\n", drone->id);
    }
    else {
        printf("Drone %d clearing airspace and landing at %s...\n", drone->id, drone->currentLocation);
        drone->isFlying = false;
        drone->batteryLevel -= 10;
    }
}

void rechargeDrones(Drone drones[MAX_DRONES]) {
    for(int i = 0; i < MAX_DRONES; i++) {
        drones[i].batteryLevel = 100;
        printf("Drone %d recharged to 100%%.\n", drones[i].id);
    }
}

int main() {
    Drone drones[MAX_DRONES];
    initializeDrones(drones);

    char command[MAX_COMMAND_LENGTH];

    printf("Welcome to the C Drone Remote Control Program!\n");

    while(true) {
        printf("\n");
        displayDrones(drones);
        printf("\nEnter a command (fly/land/recharge/quit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if(strncmp(command, "fly", 3) == 0) {
            int droneId;
            char destination[50];

            printf("Enter drone ID: ");
            scanf("%d", &droneId);

            if(droneId > 0 && droneId <= MAX_DRONES) {
                printf("Enter destination: ");
                scanf("%s", destination);
                flyDrone(&drones[droneId-1], destination);
            }
            else {
                printf("Invalid drone ID.\n");
            }
        }

        else if(strncmp(command, "land", 4) == 0) {
            int droneId;

            printf("Enter drone ID: ");
            scanf("%d", &droneId);

            if(droneId > 0 && droneId <= MAX_DRONES) {
                landDrone(&drones[droneId-1]);
            }
            else {
                printf("Invalid drone ID.\n");
            }
        }

        else if(strncmp(command, "recharge", 8) == 0) {
            rechargeDrones(drones);
        }
        
        else if(strncmp(command, "quit", 4) == 0) {
            printf("Shutting down C Drone Remote Control Program...\n");
            break;
        }

        else {
            printf("Invalid command.\n");
        }

        // Clear input buffer
        while(getchar() != '\n');
    }

    return 0;
}