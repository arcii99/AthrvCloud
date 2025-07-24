//FormAI DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void turnOnLight(int lightNum);
void turnOffLight(int lightNum);
void toggleLight(int lightNum);
void allLightsOn();
void allLightsOff();
void printCurrentState();

// Global variables
bool lights[4] = {false, false, false, false};

int main() {
    printCurrentState();

    turnOnLight(2);
    toggleLight(3);
    turnOffLight(1);
    allLightsOn();
    toggleLight(4);
    allLightsOff();
    turnOnLight(1);

    printCurrentState();

    return 0;
}

void turnOnLight(int lightNum) {
    if (lightNum >= 1 && lightNum <= 4) {
        lights[lightNum-1] = true;
        printf("Light %d turned on.\n", lightNum);
    } else {
        printf("Invalid light number.\n");
    }
}

void turnOffLight(int lightNum) {
    if (lightNum >= 1 && lightNum <= 4) {
        lights[lightNum-1] = false;
        printf("Light %d turned off.\n", lightNum);
    } else {
        printf("Invalid light number.\n");
    }
}

void toggleLight(int lightNum) {
    if (lightNum >= 1 && lightNum <= 4) {
        if (lights[lightNum-1]) {
            turnOffLight(lightNum);
        } else {
            turnOnLight(lightNum);
        }
    } else {
        printf("Invalid light number.\n");
    }
}

void allLightsOn() {
    for (int i = 0; i < 4; i++) {
        lights[i] = true;
    }
    printf("All lights turned on.\n");
}

void allLightsOff() {
    for (int i = 0; i < 4; i++) {
        lights[i] = false;
    }
    printf("All lights turned off.\n");
}

void printCurrentState() {
    printf("Current state of lights:\n");
    for (int i = 0; i < 4; i++) {
        printf("Light %d: %s\n", i+1, lights[i] ? "on" : "off");
    }
}