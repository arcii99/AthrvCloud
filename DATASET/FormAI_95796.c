//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 50

int main(){

    char command[MAX_COMMAND_LENGTH];
    int droneX = 0, droneY = 0;
    printf("Welcome to the C Drone Remote Control!\n\n");

    while(1){
        printf("Enter your command (up, down, left, right): ");
        scanf("%s", command);

        if(strcmp(command, "up") == 0){
            droneY++;
            printf("Drone moved up.\n");
        }else if(strcmp(command, "down") == 0){
            droneY--;
            printf("Drone moved down.\n");
        }else if(strcmp(command, "left") == 0){
            droneX--;
            printf("Drone moved left.\n");
        }else if(strcmp(command, "right") == 0){
            droneX++;
            printf("Drone moved right.\n");
        }else if(strcmp(command, "end") == 0){
            printf("Remote control session has ended.\n");
            break;
        }else{
            printf("Invalid command. Please try again.\n");
        }

        printf("Drone coordinates: (%d, %d)\n", droneX, droneY);
        printf("\n");
    }

    return 0;
}