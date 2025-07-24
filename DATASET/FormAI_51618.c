//FormAI DATASET v1.0 Category: Smart home light control ; Style: invasive
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// function to control the lights 
void lightControl(char* room, char* command) { 
    printf("Controlling Lights in %s Room: %s\n", room, command); 
} 

int main() { 
    char room[20]; 
    char command[20]; 

    while (1) { 
        printf("\nEnter Room Name: "); 
        scanf("%s", room); 

        if (strcmp(room, "exit") == 0) { 
            printf("Exiting Light Control System...\n"); 
            exit(0); 
        } 

        printf("Enter Command: On/OFF: "); 
        scanf("%s", command); 

        if (strcmp(command, "on") == 0 || strcmp(command, "ON") == 0) 
            lightControl(room, "ON\n"); 
        else if (strcmp(command, "off") == 0 || strcmp(command, "OFF") == 0) 
            lightControl(room, "OFF\n"); 
        else 
            printf("Invalid Command!\n"); 
    } 

    return 0; 
}