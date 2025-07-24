//FormAI DATASET v1.0 Category: Smart home light control ; Style: minimalist
#include <stdio.h>

// define constants for light status
#define OFF 0
#define ON 1

// simulate reading the sensors
int readSensor(char* sensorName) {
    printf("Reading %s sensor...\n", sensorName);
    return 1; // return 1 for a positive reading
}

// control the lights
void controlLights(int* lightStatus, char* lightName) {
    if (*lightStatus == OFF) {
        printf("%s lights are off. Turning on...\n", lightName);
        *lightStatus = ON; // update light status
    } else {
        printf("%s lights are on. Turning off...\n", lightName);
        *lightStatus = OFF; // update light status
    }
}

// main function
int main() {
    int livingRoomStatus = OFF;
    int kitchenStatus = OFF;
    
    printf("Smart Home Light Control\n");
    printf("------------------------\n");
    
    // loop indefinitely
    while (1) {
        // read the living room motion sensor
        int livingRoomSensor = readSensor("Living Room Motion");
        if (livingRoomSensor) {
            // turn the living room lights on/off
            controlLights(&livingRoomStatus, "Living Room");
        }
        
        // read the kitchen door sensor
        int kitchenSensor = readSensor("Kitchen Door");
        if (kitchenSensor) {
            // turn the kitchen lights on/off
            controlLights(&kitchenStatus, "Kitchen");
        }
    }
    
    return 0;
}