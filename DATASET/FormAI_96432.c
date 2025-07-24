//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
// This program simulates a traffic light controller at an intersection of two roads.
// The intersection has two traffic lights, one facing each road, and a pedestrian crossing signal.
// The traffic lights operate on a cycle of green light for a fixed duration, followed by yellow light for a fixed duration,
// then red light for a fixed duration before repeating the cycle.
// The pedestrian signal is only active when the traffic lights facing the pedestrian crossing are red,
// and it alternates between a white "walk" signal and a red "don't walk" signal.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN_DURATION 10 // Duration of green light in seconds
#define YELLOW_DURATION 3 // Duration of yellow light in seconds
#define RED_DURATION 20 // Duration of red light in seconds
#define PEDESTRIAN_DURATION 5 // Duration of pedestrian signal in seconds

enum TrafficLightColor { GREEN, YELLOW, RED };
enum PedestrianSignal { WALK, DONT_WALK };

// Function prototypes
void operateTrafficLights(enum TrafficLightColor leftLight, enum TrafficLightColor rightLight);
void operatePedestrianSignal(enum TrafficLightColor leftLight, enum TrafficLightColor rightLight, enum PedestrianSignal *pedSignal);
void printTrafficLights(enum TrafficLightColor leftLight, enum TrafficLightColor rightLight, enum PedestrianSignal pedSignal);

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    enum TrafficLightColor leftLight = GREEN;
    enum TrafficLightColor rightLight = RED;
    enum PedestrianSignal pedSignal = DONT_WALK;

    while (1) { // Loop infinitely
        operateTrafficLights(leftLight, rightLight); // Operate traffic lights
        operatePedestrianSignal(leftLight, rightLight, &pedSignal); // Operate pedestrian signal
        printTrafficLights(leftLight, rightLight, pedSignal); // Print traffic light status

        // Switch traffic light colors after cycle is complete
        if (leftLight == GREEN && rightLight == RED) {
            leftLight = YELLOW;
            rightLight = GREEN;
        } else if (leftLight == YELLOW) {
            leftLight = RED;
        } else if (rightLight == GREEN && leftLight == RED) {
            rightLight = YELLOW;
        } else if (rightLight == YELLOW) {
            rightLight = RED;
        }

        // Wait for a random amount of time before starting next cycle
        int waitTime = rand() % 6 + 10; // Generate random number between 10 and 15
        printf("Waiting %d seconds...\n\n", waitTime);
        for (int i = 0; i < waitTime; i++) {
            sleep(1); // Wait for one second
        }
    }

    return 0;
}

// Simulates the operation of the traffic lights
void operateTrafficLights(enum TrafficLightColor leftLight, enum TrafficLightColor rightLight) {
    printf("Traffic lights:\n");
    switch (leftLight) {
        case GREEN:
            printf("  Left:  GREEN\n");
            break;
        case YELLOW:
            printf("  Left:  YELLOW\n");
            break;
        case RED:
            printf("  Left:  RED\n");
            break;
    }
    switch (rightLight) {
        case GREEN:
            printf("  Right: GREEN\n");
            break;
        case YELLOW:
            printf("  Right: YELLOW\n");
            break;
        case RED:
            printf("  Right: RED\n");
            break;
    }
}

// Simulates the operation of the pedestrian signal
void operatePedestrianSignal(enum TrafficLightColor leftLight, enum TrafficLightColor rightLight, enum PedestrianSignal *pedSignal) {
    printf("Pedestrian signal:\n");
    if (*pedSignal == DONT_WALK) {
        printf("  Don't Walk\n");

        if (leftLight == RED || rightLight == RED) {
            *pedSignal = WALK;
        }
    } else {
        printf("  Walk\n");

        // Wait for fixed duration before switching back to don't walk signal
        for (int i = 0; i < PEDESTRIAN_DURATION; i++) {
            sleep(1); // Wait for one second
        }

        *pedSignal = DONT_WALK;
    }
}

// Prints the current status of the traffic lights and pedestrian signal
void printTrafficLights(enum TrafficLightColor leftLight, enum TrafficLightColor rightLight, enum PedestrianSignal pedSignal) {
    printf("\nCurrent status:\n");
    operateTrafficLights(leftLight, rightLight);
    operatePedestrianSignal(leftLight, rightLight, &pedSignal);
    printf("\n");
}