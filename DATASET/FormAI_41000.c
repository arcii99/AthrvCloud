//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

#define NUM_LIGHTS 3

enum LightState {
    OFF = 0,
    GREEN,
    YELLOW,
    RED
};

struct TrafficLight {
    enum LightState state;
    int duration;
};

void printLightState(enum LightState state) {
    switch (state) {
        case OFF:
            printf("Off");
            break;
        case GREEN:
            printf("Green");
            break;
        case YELLOW:
            printf("Yellow");
            break;
        case RED:
            printf("Red");
            break;
        default:
            break;
    }
}

void printTrafficLights(struct TrafficLight *lights, int numLights) {
    for (int i = 0; i < numLights; i++) {
        printf("\nLight %d: ", i + 1);
        printLightState(lights[i].state);
        printf(", Duration: %d seconds", lights[i].duration);
    }
}

void turnOffAllLights(struct TrafficLight *lights, int numLights) {
    for (int i = 0; i < numLights; i++) {
        lights[i].state = OFF;
    }
}

void setLightState(struct TrafficLight *light, enum LightState state, int duration) {
    light->state = state;
    light->duration = duration;
}

void runTrafficLightController(struct TrafficLight *lights, int numLights) {
    int currentLightIndex = 0, elapsedTime = 0;

    while(true) {
        // Turn off all lights and reset current light index if we have looped through all the lights
        if (currentLightIndex >= numLights) {
            currentLightIndex = 0;
            turnOffAllLights(lights, numLights);
        }

        // Set the current light to green and the rest to red
        setLightState(&lights[currentLightIndex], GREEN, 10);
        for (int i = 0; i < numLights; i++) {
            if (i != currentLightIndex) {
                setLightState(&lights[i], RED, 0);
            }
        }
        elapsedTime = 0;

        // Keep the light green for 10 seconds
        while (elapsedTime < 10) {
            printf("\nCurrent Light: ");
            printLightState(lights[currentLightIndex].state);
            printf(", Time remaining: %d seconds", 10 - elapsedTime);
            printTrafficLights(lights, numLights);
            elapsedTime++;
        }

        // Set the current light to yellow for 2 seconds
        setLightState(&lights[currentLightIndex], YELLOW, 2);
        elapsedTime = 0;

        // Keep the light yellow for 2 seconds
        while (elapsedTime < 2) {
            printf("\nCurrent Light: ");
            printLightState(lights[currentLightIndex].state);
            printf(", Time remaining: %d seconds", 2 - elapsedTime);
            printTrafficLights(lights, numLights);
            elapsedTime++;
        }

        // Set the current light to red and move on to the next light
        setLightState(&lights[currentLightIndex], RED, 10);
        currentLightIndex++;
    }
}

int main() {
    struct TrafficLight trafficLights[NUM_LIGHTS];

    // Set up the traffic light states and durations
    for (int i = 0; i < NUM_LIGHTS; i++) {
        trafficLights[i].state = OFF;
        trafficLights[i].duration = 0;
    }

    // Run the traffic light controller
    runTrafficLightController(trafficLights, NUM_LIGHTS);

    return 0;
}