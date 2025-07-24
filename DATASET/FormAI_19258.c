//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function definitions
void greenLight();
void yellowLight();
void redLight();

// Global variables
int currentState; // 0: Green | 1: Yellow | 2: Red

int main() {
    currentState = 0; // Set initial state to Green
    
    while (1) { // Loop indefinitely
        switch (currentState) {
            case 0: // Green
                greenLight();
                // Transition to Yellow
                currentState = 1;
                break;
            case 1: // Yellow
                yellowLight();
                // Transition to Red
                currentState = 2;
                break;
            case 2: // Red
                redLight();
                // Transition to Green
                currentState = 0;
                break;
        }
    }

    return 0;
}

void greenLight() {
    printf("Green Light Active\n");
    // Wait for specified duration
    for (int i = 0; i < 10; i++) {
        printf("Time remaining: %d\n", 10 - i);
        sleep(1);
    }
}

void yellowLight() {
    printf("Yellow Light Active\n");
    // Wait for specified duration
    for (int i = 0; i < 5; i++) {
        printf("Time remaining: %d\n", 5 - i);
        sleep(1);
    }
}

void redLight() {
    printf("Red Light Active\n");
    // Wait for specified duration
    for (int i = 0; i < 15; i++) {
        printf("Time remaining: %d\n", 15 - i);
        sleep(1);
    }
}