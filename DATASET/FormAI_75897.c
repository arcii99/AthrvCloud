//FormAI DATASET v1.0 Category: Smart home automation ; Style: genious
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate the status of a smart device
int simulateStatus(int probability) {
    int random = rand() % 100 + 1;

    if (random <= probability) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    srand(time(0));

    // Simulating the status of various devices using probabilities
    int bedRoomLightStatus = simulateStatus(80);
    int kitchenLightStatus = simulateStatus(70);
    int fanStatus = simulateStatus(50);
    int airPurifierStatus = simulateStatus(30);
    int tvStatus = simulateStatus(20);

    // Opening the automation app
    printf("Welcome to SmartHome Automation App\n\n");

    // Controlling the bedroom light
    printf("Bedroom Light\n");

    if (bedRoomLightStatus == 1) {
        printf("Status: On\n\n");
    } else {
        printf("Status: Off\n\n");
    }

    // Controlling the kitchen light
    printf("Kitchen Light\n");

    if (kitchenLightStatus == 1) {
        printf("Status: On\n\n");
    } else {
        printf("Status: Off\n\n");
    }

    // Controlling the Fan
    printf("Fan\n");

    if (fanStatus == 1) {
        printf("Status: On\n\n");
    } else {
        printf("Status: Off\n\n");
    }

    // Controlling the Air Purifier
    printf("Air Purifier\n");

    if (airPurifierStatus == 1) {
        printf("Status: On\n\n");
    } else {
        printf("Status: Off\n\n");
    }

    // Controlling the TV
    printf("TV\n");

    if (tvStatus == 1) {
        printf("Status: On\n\n");
    } else {
        printf("Status: Off\n\n");
    }

    // Closing the automation app
    printf("Thank you for using SmartHome Automation App\n");

    return 0;
}