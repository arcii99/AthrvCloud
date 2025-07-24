//FormAI DATASET v1.0 Category: Smart home light control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

typedef struct Light {
    int id;
    bool isOn;
} Light;

void printStatus(Light lights[]) {
    printf("Light Status:\n");
    for (int i=0; i<MAX_LIGHTS; i++) {
        printf("Light %d is turned %s\n", lights[i].id, lights[i].isOn ? "on" : "off");
    }
}

void turnOn(Light lights[], int id) {
    if (id < 1 || id > MAX_LIGHTS) {
        printf("Invalid light ID\n");
        return;
    }
    lights[id-1].isOn = true;
    printf("Light %d turned on\n", id);
}

void turnOff(Light lights[], int id) {
    if (id < 1 || id > MAX_LIGHTS) {
        printf("Invalid light ID\n");
        return;
    }
    lights[id-1].isOn = false;
    printf("Light %d turned off\n", id);
}

int main() {
    Light lights[MAX_LIGHTS];
    for (int i=0; i<MAX_LIGHTS; i++) {
        lights[i].id = i+1;
        lights[i].isOn = false;
    }
    printStatus(lights);

    turnOn(lights, 3);
    turnOn(lights, 5);
    printStatus(lights);

    turnOff(lights, 3);
    printStatus(lights);

    return 0;
}