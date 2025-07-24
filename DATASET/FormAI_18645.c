//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COMMAND_LENGTH 20

void handleCommand(char command[MAX_COMMAND_LENGTH]);

int main(){
    char input[MAX_COMMAND_LENGTH];

    while(1){
        printf("\nEnter drone command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        handleCommand(input);
    }

    return 0;
}

void handleCommand(char command[MAX_COMMAND_LENGTH]){
    const char* takeoff = "takeoff";
    const char* land = "land";
    const char* ascend = "ascend";
    const char* descend = "descend";
    const char* rotateLeft = "rotate_left";
    const char* rotateRight = "rotate_right";
    const char* moveForward = "move_forward";
    const char* moveBackward = "move_backward";
    const char* moveLeft = "move_left";
    const char* moveRight = "move_right";

    if(strcmp(command, takeoff) == 0){
        printf("Command Received: Takeoff\n");
        // Code to initiate takeoff sequence goes here
    }
    else if(strcmp(command, land) == 0){
        printf("Command Received: Land\n");
        // Code to initiate land sequence goes here
    }
    else if(strcmp(command, ascend) == 0){
        printf("Command Received: Ascend\n");
        // Code to initiate ascending sequence goes here
    }
    else if(strcmp(command, descend) == 0){
        printf("Command Received: Descend\n");
        // Code to initiate descending sequence goes here
    }
    else if(strcmp(command, rotateLeft) == 0){
        printf("Command Received: Rotate Left\n");
        // Code to initiate rotate left sequence goes here
    }
    else if(strcmp(command, rotateRight) == 0){
        printf("Command Received: Rotate Right\n");
        // Code to initiate rotate right sequence goes here
    }
    else if(strcmp(command, moveForward) == 0){
        printf("Command Received: Move Forward\n");
        // Code to initiate move forward sequence goes here
    }
    else if(strcmp(command, moveBackward) == 0){
        printf("Command Received: Move Backward\n");
        // Code to initiate move backward sequence goes here
    }
    else if(strcmp(command, moveLeft) == 0){
        printf("Command Received: Move Left\n");
        // Code to initiate move left sequence goes here
    }
    else if(strcmp(command, moveRight) == 0){
        printf("Command Received: Move Right\n");
        // Code to initiate move right sequence goes here
    }
    else{
        printf("Invalid Command\n");
    }
}