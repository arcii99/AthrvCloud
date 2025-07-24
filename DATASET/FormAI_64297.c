//FormAI DATASET v1.0 Category: Smart home automation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SmartDevice {
    char name[20];
    int power;
    int state;
};

void print_device(struct SmartDevice device) {
    printf("%s is turned %s with power level %d.\n", device.name, device.state ? "ON" : "OFF", device.power);
}

int main() {
    struct SmartDevice light_bulb;
    strcpy(light_bulb.name, "Living Room Light");
    light_bulb.power = 60;
    light_bulb.state = 0;

    print_device(light_bulb);
    printf("Turning on %s...\n", light_bulb.name);
    light_bulb.state = 1;
    print_device(light_bulb);

    struct SmartDevice thermostat;
    strcpy(thermostat.name, "Living Room Thermostat");
    thermostat.power = 50;
    thermostat.state = 0;

    print_device(thermostat);
    printf("Turning on %s...\n", thermostat.name);
    thermostat.state = 1;
    print_device(thermostat);

    printf("Adjusting %s temperature to 70 degrees...\n", thermostat.name);
    printf("%s temperature adjusted!\n", thermostat.name);

    struct SmartDevice security;
    strcpy(security.name, "Living Room Security System");
    security.power = 100;
    security.state = 0;

    print_device(security);
    printf("Turning on %s...\n", security.name);
    security.state = 1;
    print_device(security);

    printf("Arming %s...\n", security.name);
    printf("%s armed!\n", security.name);

    return 0;
}