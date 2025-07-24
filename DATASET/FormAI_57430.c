//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Light {
    int id;
    int status;  // 0 for OFF and 1 for ON
    int intensity;  // 0 to 100
};

struct Home {
    char name[30];
    struct Light light1;
    struct Light light2;
};

void turnOn(struct Light* light) {
    light->status = 1;
}

void turnOff(struct Light* light) {
    light->status = 0;
}

void setIntensity(struct Light* light, int value) {
    light->intensity = value;
}

void printStatus(struct Light light) {
    printf("     Status: %s\n", light.status ? "ON" : "OFF");
    printf("  Intensity: %d\n", light.intensity);
}

void printAllLightStatus(struct Home home) {
    printf("Light 1:\n");
    printStatus(home.light1);
    printf("Light 2:\n");
    printStatus(home.light2);
}

int main() {
    struct Home myHome = {
        .name = "My Smart Home",
        .light1 = {
            .id = 1,
            .status = 0,
            .intensity = 0
        },
        .light2 = {
            .id = 2,
            .status = 0,
            .intensity = 0
        }
    };

    printAllLightStatus(myHome);

    turnOn(&myHome.light1);
    setIntensity(&myHome.light1, 50);
    turnOn(&myHome.light2);

    printf("After turning on the lights and setting intensity of light 1:\n");
    printAllLightStatus(myHome);

    turnOff(&myHome.light1);
    setIntensity(&myHome.light2, 75);

    printf("After turning off light 1 and setting intensity of light 2:\n");
    printAllLightStatus(myHome);

    return 0;
}