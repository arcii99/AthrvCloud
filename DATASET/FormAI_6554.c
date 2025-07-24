//FormAI DATASET v1.0 Category: Smart home light control ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to turn on the lights
void turn_on_lights() {
    printf("Lights turned on!\n");
}

// Function to turn off the lights
void turn_off_lights() {
    printf("Lights turned off!\n");
}

int main() {
    char command[20];
    while(1) {
        printf("Enter command (on/off): ");
        scanf("%s", command);
        if(strcmp(command, "on") == 0) {
            turn_on_lights();
        } else if(strcmp(command, "off") == 0) {
            turn_off_lights();
        } else {
            printf("Invalid command!\n");
            continue;
        }
    }
    return 0;
}