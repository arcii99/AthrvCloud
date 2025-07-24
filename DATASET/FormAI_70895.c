//FormAI DATASET v1.0 Category: Smart home light control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void turnOnLights(int *lights, int size) {
    for(int i = 0; i < size; i++) {
        lights[i] = 1;
    }
    printf("Lights turned on.\n");
}

void turnOffLights(int *lights, int size) {
    for(int i = 0; i < size; i++) {
        lights[i] = 0;
    }
    printf("Lights turned off.\n");
}

int main() {
    int numLights = 4;
    int *lights = (int*)malloc(numLights * sizeof(int));

    printf("Welcome to Smart Home Light Control!\n");

    while(1) {
        printf("Enter a command (\"on\", \"off\", \"exit\"): ");
        char command[10];
        scanf("%s", command);

        if(strcmp(command, "on") == 0) {
            turnOnLights(lights, numLights);
        }
        else if(strcmp(command, "off") == 0) {
            turnOffLights(lights, numLights);
        }
        else if(strcmp(command, "exit") == 0) {
            free(lights);
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}