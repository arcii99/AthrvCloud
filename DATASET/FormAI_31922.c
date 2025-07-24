//FormAI DATASET v1.0 Category: Smart home automation ; Style: dynamic
#include <stdio.h>

// Define Constants for Devices
#define NUM_LIGHTS 4
#define NUM_TEMPERATURE_SENSORS 2
#define NUM_DOORS 3

// Struct for temperature sensors
typedef struct {
    int id;
    float temperature;
} TemperatureSensor;

// Struct for device
typedef struct {
    int id;
    char* name;
    int isOn;
} Device;

// Struct for smart home
typedef struct {
    Device lights[NUM_LIGHTS];
    TemperatureSensor temperatureSensors[NUM_TEMPERATURE_SENSORS];
    Device doors[NUM_DOORS];
} SmartHome;

// Function to turn on a device
void turnOnDevice(Device* device) {
    device->isOn = 1;
    printf("Turned on %s\n", device->name);
}

// Function to turn off a device
void turnOffDevice(Device* device) {
    device->isOn = 0;
    printf("Turned off %s\n", device->name);
}

int main() {
    // Initialize Smart Home Devices
    Device livingRoomLight = {1, "Living Room Light", 0};
    Device kitchenLight = {2, "Kitchen Light", 0};
    Device bedroomLight = {3, "Bedroom Light", 0};
    Device outsideLight = {4, "Outside Light", 0};
    TemperatureSensor livingRoomSensor = {1, 70.5};
    TemperatureSensor bedroomSensor = {2, 68.0};
    Device frontDoor = {1, "Front Door", 0};
    Device backDoor = {2, "Back Door", 0};
    Device garageDoor = {3, "Garage Door", 0};

    // Initialize Smart Home
    SmartHome home = {
        {livingRoomLight, kitchenLight, bedroomLight, outsideLight},
        {livingRoomSensor, bedroomSensor},
        {frontDoor, backDoor, garageDoor},
    };

    // Turn on living room light
    turnOnDevice(&home.lights[0]);

    // Check temperature in living room
    printf("Temperature in living room: %.2f\n", home.temperatureSensors[0].temperature);

    // Open front door
    turnOnDevice(&home.doors[0]);

    // Turn off outside light
    turnOffDevice(&home.lights[3]);
    
    return 0;
}