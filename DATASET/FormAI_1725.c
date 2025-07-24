//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

// Define the color codes of the lights
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

// Define the duration of each light in seconds
#define RED_LIGHT_DURATION 10
#define GREEN_LIGHT_DURATION 15
#define YELLOW_LIGHT_DURATION 2

// Define the state of the lights
enum LightState {
    RED_LIGHT,
    YELLOW_LIGHT,
    GREEN_LIGHT
};

typedef enum LightState LightState;

// Define the state of the traffic controller
enum ControllerState {
    STOP,
    CAUTION,
    GO
};

typedef enum ControllerState ControllerState;

// Initialize the state of the traffic controller
ControllerState controllerState = STOP;

// Initialize the state of the lights
LightState lightState = RED_LIGHT;

// Initialize the duration of the lights
int lightDuration = RED_LIGHT_DURATION;

// Initialize the timer
int timer = 0;

int main() {
    // Loop through the traffic controller states
    while (true) {
        // Print the current state of the controller
        printf("\nCurrent State: ");
        switch (controllerState) {
            case STOP:
                printf("STOP\n");
                break;
            case CAUTION:
                printf("CAUTION\n");
                break;
            case GO:
                printf("GO\n");
                break;
        }

        // Print the current state of the lights
        printf("Red Light: %s%s%s\n", (lightState == RED_LIGHT && controllerState == STOP) ? RED : RESET, (lightState == RED_LIGHT) ? "ON" : "OFF", RESET);
        printf("Yellow Light: %s%s%s\n", (lightState == YELLOW_LIGHT && controllerState == CAUTION) ? YELLOW : RESET, (lightState == YELLOW_LIGHT) ? "ON" : "OFF", RESET);
        printf("Green Light: %s%s%s\n", (lightState == GREEN_LIGHT && controllerState == GO) ? GREEN : RESET, (lightState == GREEN_LIGHT) ? "ON" : "OFF", RESET);

        // Decrement the timer every second
        timer--;
        if (timer < 0) {
            timer = 0;
        }

        // Check if the duration of the light has ended
        if (timer == 0) {
            // Change to the next light
            switch (lightState) {
                case RED_LIGHT:
                    lightState = GREEN_LIGHT;
                    lightDuration = GREEN_LIGHT_DURATION;
                    break;
                case YELLOW_LIGHT:
                    lightState = RED_LIGHT;
                    lightDuration = RED_LIGHT_DURATION;
                    break;
                case GREEN_LIGHT:
                    lightState = YELLOW_LIGHT;
                    lightDuration = YELLOW_LIGHT_DURATION;
                    break;
            }

            // Reset the timer
            timer = lightDuration;
        }

        // Check for user input
        int input = getchar();
        if (input == 's' || input == 'S') {
            controllerState = STOP;
            lightState = RED_LIGHT;
            lightDuration = RED_LIGHT_DURATION;
            timer = lightDuration;
        } else if (input == 'c' || input == 'C') {
            controllerState = CAUTION;
            lightState = YELLOW_LIGHT;
            lightDuration = YELLOW_LIGHT_DURATION;
            timer = lightDuration;
        } else if (input == 'g' || input == 'G') {
            controllerState = GO;
            lightState = GREEN_LIGHT;
            lightDuration = GREEN_LIGHT_DURATION;
            timer = lightDuration;
        }
    }

    return 0;
}