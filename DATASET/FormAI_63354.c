//FormAI DATASET v1.0 Category: Smart home light control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BULBS 10

// A structure representing the state of a light bulb
typedef struct
{
    bool isOn;
    int brightnessLevel;
} LightBulb;

// A structure representing the state of the smart home light controller
typedef struct
{
    LightBulb bulbs[MAX_BULBS];
    int numBulbs;
} SmartHomeLightController;

// Function to turn on/off a specific light bulb
void toggleLightBulb(SmartHomeLightController *controller, int bulbIndex, bool turnOn)
{
    if (bulbIndex < 0 || bulbIndex >= controller->numBulbs)
    {
        printf("Invalid bulb index!\n");
        return;
    }

    LightBulb *bulb = &(controller->bulbs[bulbIndex]);

    if (turnOn)
    {
        bulb->isOn = true;
        printf("Bulb %d turned on\n", bulbIndex);
    }
    else
    {
        bulb->isOn = false;
        printf("Bulb %d turned off\n", bulbIndex);
    }
}

// Function to set the brightness level of a specific light bulb
void setBrightnessLevel(SmartHomeLightController *controller, int bulbIndex, int brightnessLevel)
{
    if (bulbIndex < 0 || bulbIndex >= controller->numBulbs)
    {
        printf("Invalid bulb index!\n");
        return;
    }

    LightBulb *bulb = &(controller->bulbs[bulbIndex]);

    if (brightnessLevel < 0 || brightnessLevel > 100)
    {
        printf("Invalid brightness level!\n");
        return;
    }

    bulb->brightnessLevel = brightnessLevel;

    printf("Bulb %d brightness level set to %d\n", bulbIndex, brightnessLevel);
}

int main()
{
    SmartHomeLightController controller;

    // Initialize the controller with some bulbs
    controller.numBulbs = 3;
    controller.bulbs[0] = (LightBulb) {.isOn = false, .brightnessLevel = 0};
    controller.bulbs[1] = (LightBulb) {.isOn = true, .brightnessLevel = 50};
    controller.bulbs[2] = (LightBulb) {.isOn = true, .brightnessLevel = 100};

    // Toggle on/off some bulbs
    toggleLightBulb(&controller, 0, true);
    toggleLightBulb(&controller, 1, false);

    // Set brightness level of a bulb
    setBrightnessLevel(&controller, 2, 75);

    // Print current state of all bulbs
    printf("Current state of all bulbs:\n");
    for (int i = 0; i < controller.numBulbs; i++)
    {
        LightBulb *bulb = &(controller.bulbs[i]);
        printf("Bulb %d: %s, brightness level %d\n", i, bulb->isOn ? "on" : "off", bulb->brightnessLevel);
    }

    return 0;
}