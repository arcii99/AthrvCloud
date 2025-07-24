//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: immersive
#include <stdio.h>

// Function to take input from user for selecting drone mode
void selectMode(int *mode) {
    printf("Select drone mode: \n1. Autonomous \n2. Manual \n3. GPS tracking\n");
    scanf("%d", mode); // taking input from user
}

// Function to initiate autonomous mode
void autonomousMode() {
    printf("Autonomous mode initiated.\n");
    // Some code to control the drone autonomously
}

// Function to initiate manual mode
void manualMode() {
    printf("Manual mode initiated.\n");
    // Some code to control the drone manually
}

// Function to initiate GPS tracking mode
void gpsTrackingMode() {
    printf("GPS tracking mode initiated.\n");
    // Some code to track the drone using GPS
}

// Main function
int main() {
    int mode;
    selectMode(&mode); // calling selectMode function to get the selected drone mode
    switch (mode) {
        case 1:
            autonomousMode(); // calling autonomousMode function for autonomous mode
            break;
        case 2:
            manualMode(); // calling manualMode function for manual mode
            break;
        case 3:
            gpsTrackingMode(); // calling gpsTrackingMode function for GPS tracking mode
            break;
        default:
            printf("Invalid mode selected."); // error if invalid selection is made
            break;
    }
    return 0;
}