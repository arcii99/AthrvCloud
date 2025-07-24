//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char droneCommand[100];

    while(1){
        printf("Enter command for drone: ");
        scanf("%s", droneCommand);
        
        if(strcmp(droneCommand, "takeoff") == 0){
            printf("Drone takes off!\n");
        }
        else if(strcmp(droneCommand, "land") == 0){
            printf("Drone lands safely.\n");
        }
        else if(strcmp(droneCommand, "forward") == 0){
            printf("Drone moves forward.\n");
        }
        else if(strcmp(droneCommand, "backward") == 0){
            printf("Drone moves backward.\n");
        }
        else if(strcmp(droneCommand, "left") == 0){
            printf("Drone moves left.\n");
        }
        else if(strcmp(droneCommand, "right") == 0){
            printf("Drone moves right.\n");
        }
        else if(strcmp(droneCommand, "descend") == 0){
            printf("Drone descends safely.\n");
        }
        else if(strcmp(droneCommand, "ascend") == 0){
            printf("Drone ascends safely.\n");
        }
        else if(strcmp(droneCommand, "exit") == 0){
            printf("Drone remote control program exits.\n");
            break;
        }
        else{
            printf("Invalid command. Please enter a valid command.\n");
        }
    }

    return 0;
}