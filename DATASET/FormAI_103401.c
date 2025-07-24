//FormAI DATASET v1.0 Category: Smart home automation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 20

struct Device {
    char name[MAX_NAME_LENGTH];
    bool state;
    int brightness;
};

struct SmartHome {
    struct Device devices[MAX_DEVICES];
    int numDevices;
    bool status;
};

void addDevice(struct SmartHome *home, char *name) {
    if (home->numDevices < MAX_DEVICES) {
        struct Device newDevice;
        strcpy(newDevice.name, name);
        newDevice.state = false;
        newDevice.brightness = 0;

        home->devices[home->numDevices] = newDevice;
        home->numDevices++;

        printf("%s added to smart home\n", name);
    } else {
        printf("Max number of devices reached\n");
    }
}

void removeDevice(struct SmartHome *home, char *name) {
    int deviceIndex = -1;

    for (int i = 0; i < home->numDevices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            deviceIndex = i;
            break;
        }
    }

    if (deviceIndex != -1) {
        for (int i = deviceIndex; i < home->numDevices - 1; i++) {
            home->devices[i] = home->devices[i+1];
        }

        home->numDevices--;

        printf("%s removed from smart home\n", name);
    } else {
        printf("%s is not a device in the smart home\n", name);
    }
}

void turnOnDevice(struct SmartHome *home, char *name) {
    int deviceIndex = -1;

    for (int i = 0; i < home->numDevices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            deviceIndex = i;
            break;
        }
    }

    if (deviceIndex != -1) {
        home->devices[deviceIndex].state = true;
        printf("%s turned on\n", name);
    } else {
        printf("%s is not a device in the smart home\n", name);
    }
}

void turnOffDevice(struct SmartHome *home, char *name) {
    int deviceIndex = -1;

    for (int i = 0; i < home->numDevices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            deviceIndex = i;
            break;
        }
    }

    if (deviceIndex != -1) {
        home->devices[deviceIndex].state = false;
        printf("%s turned off\n", name);
    } else {
        printf("%s is not a device in the smart home\n", name);
    }
}

void setBrightness(struct SmartHome *home, char *name, int brightness) {
    int deviceIndex = -1;

    for (int i = 0; i < home->numDevices; i++) {
        if (strcmp(home->devices[i].name, name) == 0) {
            deviceIndex = i;
            break;
        }
    }

    if (deviceIndex != -1) {
        home->devices[deviceIndex].brightness = brightness;
        printf("%s brightness set to %d\n", name, brightness);
    } else {
        printf("%s is not a device in the smart home\n", name);
    }
}

void turnOnAllDevices(struct SmartHome *home) {
    for (int i = 0; i < home->numDevices; i++) {
        home->devices[i].state = true;
    }

    printf("All devices turned on\n");
}

void turnOffAllDevices(struct SmartHome *home) {
    for (int i = 0; i < home->numDevices; i++) {
        home->devices[i].state = false;
    }

    printf("All devices turned off\n");
}

int main() {
    struct SmartHome home;
    home.numDevices = 0;
    home.status = false;

    printf("Welcome to your smart home\n");

    // add some devices

    addDevice(&home, "Living room light");
    addDevice(&home, "Kitchen light");
    addDevice(&home, "Bedroom light");
    addDevice(&home, "Front door lock");

    // turn on living room light and set brightness

    turnOnDevice(&home, "Living room light");
    setBrightness(&home, "Living room light", 50);

    // turn off front door lock

    turnOffDevice(&home, "Front door lock");

    // turn on all devices

    turnOnAllDevices(&home);

    // turn off the kitchen light

    turnOffDevice(&home, "Kitchen light");

    // turn off all devices

    turnOffAllDevices(&home);

    // remove the bedroom light

    removeDevice(&home, "Bedroom light");

    return 0;
}