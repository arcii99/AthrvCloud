//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define Traffic Light Colors
#define RED 1
#define YELLOW 2
#define GREEN 3

// Define Time Durations
#define RED_DURATION 10
#define YELLOW_DURATION 3
#define GREEN_DURATION 15

// Declare Traffic Light Struct
struct TrafficLight {
    int color;
    int duration;
};

// Function that returns a random Traffic Light
struct TrafficLight randomTrafficLight() {
    struct TrafficLight tl;
    int randNum = rand() % 3 + 1;

    switch (randNum) {
        case RED:
            tl.color = RED;
            tl.duration = RED_DURATION;
            break;
        case YELLOW:
            tl.color = YELLOW;
            tl.duration = YELLOW_DURATION;
            break;
        case GREEN:
            tl.color = GREEN;
            tl.duration = GREEN_DURATION;
            break;
        default:
            printf("Error: Invalid Traffic Light Color\n");
            exit(1);
    }
    return tl;
}

// Main Function
int main() {
    // Seed Random Number Generator
    srand(time(NULL));

    // Create Initial Traffic Light
    struct TrafficLight currentLight = randomTrafficLight();
    printf("Current Light is: ");
    if (currentLight.color == RED) {
        printf("RED\n");
    } else if (currentLight.color == YELLOW) {
        printf("YELLOW\n");
    } else if (currentLight.color == GREEN) {
        printf("GREEN\n");
    }

    // Loop Through 10 Traffic Lights
    for (int i = 0; i < 10; i++) {
        // Wait for Current Traffic Light Duration
        printf("Waiting for %d seconds\n", currentLight.duration);
        sleep(currentLight.duration);

        // Change to Next Traffic Light
        struct TrafficLight nextLight;
        do {
            nextLight = randomTrafficLight();
        } while (nextLight.color == currentLight.color);

        // Update Current Light and Print Status
        currentLight = nextLight;
        printf("Current Light is: ");
        if (currentLight.color == RED) {
            printf("RED\n");
        } else if (currentLight.color == YELLOW) {
            printf("YELLOW\n");
        } else if (currentLight.color == GREEN) {
            printf("GREEN\n");
        }
    }

    return 0;
}