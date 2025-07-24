//FormAI DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include <stdio.h>

// Function to turn on lights
void turnOnLights() {
    printf("Lights are now on.\n");
}

// Function to turn off lights
void turnOffLights() {
    printf("Lights are now off.\n");
}

int main() {
    int hourOfDay;
    int motionDetected;

    printf("Enter the hour of the day (0-23): ");
    scanf("%d", &hourOfDay);

    printf("Motion detected? (1 for yes, 0 for no): ");
    scanf("%d", &motionDetected);

    if(hourOfDay < 7 || hourOfDay > 20) {
        turnOffLights();
    } else if(hourOfDay >= 7 && hourOfDay <= 20) {
        if(motionDetected) {
            turnOnLights();
        } else {
            turnOffLights();
        }
    } else {
        printf("Invalid input. Please enter numbers between 0 and 23 for hour of day.\n");
    }

    return 0;
}