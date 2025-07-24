//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Enumeration to define the states of Traffic Lights
enum LightsState {
    RED,
    YELLOW,
    GREEN
};

// Traffic Light struct contains state, duration, and timer
struct TrafficLight {
    enum LightsState state;
    int duration;
    int timer;
};

// Function to print current traffic light state
void printState(struct TrafficLight tLight) {
    switch(tLight.state) {
        case RED:
            printf("Traffic Light is currently RED\n");
            break;
        case YELLOW:
            printf("Traffic Light is currently YELLOW\n");
            break;
        case GREEN:
            printf("Traffic Light is currently GREEN\n");
            break;
        default:
            printf("Traffic Light is malfunctioning\n");
            break;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare and initialize Traffic Light structs
    struct TrafficLight northSouthLight = { RED, 10, 0 };
    struct TrafficLight eastWestLight = { GREEN, 20, 0 };

    // Loop for simulating traffic light changes
    while(true) {
        printf("\n--------------------------------\n");

        // Print current state of Traffic Lights
        printState(northSouthLight);
        printState(eastWestLight);

        // Check the status of the North-South traffic light
        switch(northSouthLight.state) {
            case RED:
                if(northSouthLight.timer >= northSouthLight.duration) {
                    northSouthLight.state = GREEN;
                    northSouthLight.timer = 0;
                    eastWestLight.state = RED;
                    eastWestLight.timer = 0;
                } else {
                    northSouthLight.timer++;
                }
                break;
            case YELLOW:
                if(northSouthLight.timer >= northSouthLight.duration) {
                    northSouthLight.state = RED;
                    northSouthLight.timer = 0;
                } else {
                    northSouthLight.timer++;
                }
                break;
            case GREEN:
                if(northSouthLight.timer >= northSouthLight.duration) {
                    northSouthLight.state = YELLOW;
                    northSouthLight.timer = 0;
                } else {
                    northSouthLight.timer++;
                }
                break;
            default:
                printf("North-South Traffic Light Malfunctioning\n");
                break;
        }

        // Check the status of the East-West traffic light
        switch(eastWestLight.state) {
            case RED:
                if(eastWestLight.timer >= eastWestLight.duration) {
                    eastWestLight.state = GREEN;
                    eastWestLight.timer = 0;
                    northSouthLight.state = RED;
                    northSouthLight.timer = 0;
                } else {
                    eastWestLight.timer++;
                }
                break;
            case YELLOW:
                if(eastWestLight.timer >= eastWestLight.duration) {
                    eastWestLight.state = RED;
                    eastWestLight.timer = 0;
                } else {
                    eastWestLight.timer++;
                }
                break;
            case GREEN:
                if(eastWestLight.timer >= eastWestLight.duration) {
                    eastWestLight.state = YELLOW;
                    eastWestLight.timer = 0;
                } else {
                    eastWestLight.timer++;
                }
                break;
            default:
                printf("East-West Traffic Light Malfunctioning\n");
                break;
        }

        // Wait a random amount of time before next iteration
        int delay = rand() % 5 + 1;
        printf("Waiting %d seconds before next iteration...\n", delay);
        sleep(delay);
    }

    return 0;
}