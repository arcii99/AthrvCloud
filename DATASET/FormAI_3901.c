//FormAI DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int status = 0, exit_code = 0;
    char input[10];
    printf("Welcome to Smart Home Light Control!\n");

    // Simulation of initial power state
    char power_state[] = "off";

    while(1){
        printf("\nEnter command: ");
        fgets(input, sizeof(input), stdin);

        // Turning on light
        if (strcmp(input, "on\n") == 0) {
            // Checking if light is already on
            if(strcmp(power_state, "on") == 0){
                printf("Light is already on!\n");
            }else{
                printf("Turning light on...\n");
                // Simulating turning on light
                strcpy(power_state, "on");
            }
        }
        // Turning off light
        else if (strcmp(input, "off\n") == 0) {
            // Checking if light is already off
            if(strcmp(power_state, "off") == 0){
                printf("Light is already off!\n");
            }else{
                printf("Turning light off...\n");
                // Simulating turning off light
                strcpy(power_state, "off");
            }
        }
        // Invalid input
        else{
            printf("Invalid input!\n");
        }
    }
    return 0;
}