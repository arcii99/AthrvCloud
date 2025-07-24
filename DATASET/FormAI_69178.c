//FormAI DATASET v1.0 Category: Smart home automation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

// Interoperable smart devices
typedef struct {
    char name[20];
    bool powerStatus;
    int intensity;
} Device;

// Function to turn device on/off
void togglePower(Device* device) {
    device->powerStatus = !device->powerStatus;
    printf("%s is now %s\n", device->name, device->powerStatus ? "on" : "off");
}

// Function to adjust device intensity
void adjustIntensity(Device* device, int intensity) {
    device->intensity = intensity;
    printf("%s intensity set to %d\n", device->name, device->intensity);
}

int main() {
    // Create smart devices
    Device lightBulb = {"Light Bulb", false, 0};
    Device fan = {"Fan", false, 0};
    Device thermostat = {"Thermostat", false, 0};

    // Simulate user interaction
    togglePower(&lightBulb);
    togglePower(&fan);

    // Connect thermostat to fan and light bulb
    thermostat.powerStatus = true;
    thermostat.intensity = 25;
    fan.intensity = thermostat.intensity;
    lightBulb.intensity = thermostat.intensity;

    printf("%s is now %s with intensity %d\n", thermostat.name, thermostat.powerStatus ? "on" : "off", thermostat.intensity);
    printf("%s is now %s with intensity %d\n", fan.name, fan.powerStatus ? "on" : "off", fan.intensity);
    printf("%s is now %s with intensity %d\n", lightBulb.name, lightBulb.powerStatus ? "on" : "off", lightBulb.intensity);

    // Simulate user adjusting intensity of thermostat
    adjustIntensity(&thermostat, 50);
    fan.intensity = thermostat.intensity;
    lightBulb.intensity = thermostat.intensity;

    printf("%s intensity set to %d\n", thermostat.name, thermostat.intensity);
    printf("%s intensity set to %d\n", fan.name, fan.intensity);
    printf("%s intensity set to %d\n", lightBulb.name, lightBulb.intensity);

    // Simulate turning off thermostat
    togglePower(&thermostat);
    fan.intensity = 0;
    lightBulb.intensity = 0;

    printf("%s is now %s\n", thermostat.name, thermostat.powerStatus ? "on" : "off");
    printf("%s is now %s with intensity %d\n", fan.name, fan.powerStatus ? "on" : "off", fan.intensity);
    printf("%s is now %s with intensity %d\n", lightBulb.name, lightBulb.powerStatus ? "on" : "off", lightBulb.intensity);

    return 0;
}