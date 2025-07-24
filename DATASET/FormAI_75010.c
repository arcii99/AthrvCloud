//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Alan Touring
// This is a traffic light controller program written in Alan Turing style
#include <stdio.h>

// Function to display traffic light status
void displayLightStatus(char color[]) {
    printf("Current light: [%s]", color);
}

int main() {
    char currentLight[10] = "red"; // Current light status, default is red

    while(1) { // Loop indefinitely
        displayLightStatus(currentLight);
        printf("\n");

        if(strcmp(currentLight, "red") == 0) {
            // If current light is red, wait for 5 seconds
            printf("Waiting for 5 seconds...\n");
            sleep(5);
            // Change light to green
            strcpy(currentLight, "green");
        } else if(strcmp(currentLight, "green") == 0) {
            // If current light is green, wait for 10 seconds
            printf("Waiting for 10 seconds...\n");
            sleep(10);
            // Change light to yellow
            strcpy(currentLight, "yellow");
        } else if(strcmp(currentLight, "yellow") == 0) {
            // If current light is yellow, wait for 3 seconds
            printf("Waiting for 3 seconds...\n");
            sleep(3);
            // Change light to red
            strcpy(currentLight, "red");
        }
    }

    return 0;
}