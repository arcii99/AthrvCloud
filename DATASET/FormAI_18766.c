//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>

struct Light {
    int id;
    char room[20];
    int brightness; // % value from 1-100
    int status; // 0 = off, 1 = on
};

struct Light lightArr[50];
int numOfLights = 0;

// Function to add a new light
void addLight(char room[20], int brightness, int status) {
    lightArr[numOfLights].id = numOfLights + 1;
    strcpy(lightArr[numOfLights].room, room);
    lightArr[numOfLights].brightness = brightness;
    lightArr[numOfLights].status = status;
    numOfLights++;
}

// Function to turn on/off a specific light
void toggleLight(int id) {
    if (lightArr[id-1].status == 0) {
        lightArr[id-1].status = 1;
        printf("Light %d in %s turned on\n", id, lightArr[id-1].room);
    } else {
        lightArr[id-1].status = 0;
        printf("Light %d in %s turned off\n", id, lightArr[id-1].room);
    }
}

// Function to adjust the brightness of a specific light
void setBrightness(int id, int brightness) {
    lightArr[id-1].brightness = brightness;
    printf("Brightness for light %d in %s set to %d%%\n", id, lightArr[id-1].room, brightness);
}

int main() {
    printf("*** Smart Home Light Control ***\n\n");

    // Add some lights
    addLight("Living Room", 75, 1);
    addLight("Kitchen", 100, 1);
    addLight("Bedroom", 50, 0);
    addLight("Bathroom", 30, 0);

    printf("Current Light Status:\n");
    for (int i = 0; i < numOfLights; i++) {
        printf("%d. %s - %d%% brightness, %s\n", lightArr[i].id, lightArr[i].room, 
                                                lightArr[i].brightness, 
                                                lightArr[i].status ? "On" : "Off");
    }

    printf("\n");

    // Turn on/off and adjust the brightness of some lights
    toggleLight(3);
    setBrightness(2, 50);
    toggleLight(4);
    toggleLight(1);

    printf("\nUpdated Light Status:\n");
    for (int i = 0; i < numOfLights; i++) {
        printf("%d. %s - %d%% brightness, %s\n", lightArr[i].id, lightArr[i].room, 
                                                lightArr[i].brightness, 
                                                lightArr[i].status ? "On" : "Off");
    }
    
    return 0;
}