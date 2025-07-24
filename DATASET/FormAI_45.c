//FormAI DATASET v1.0 Category: Smart home light control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining constants for light control
#define OFF 0
#define ON 1
#define DIM 2
#define BRIGHT 3

// Function to display light status
void printStatus(char* lightName, int lightStatus) {
    printf("%s light is ", lightName);
    switch(lightStatus) {
        case OFF:
            printf("off");
            break;
        case ON:
            printf("on");
            break;
        case DIM:
            printf("dimmed");
            break;
        case BRIGHT:
            printf("bright");
            break;
        default:
            printf("invalid");
            break;
    }
    printf("\n");
}

// Function to turn on light
void turnOn(int* lightStatus) {
    *lightStatus = ON;
    printf("Light turned on.\n");
}

// Function to turn off light
void turnOff(int* lightStatus) {
    *lightStatus = OFF;
    printf("Light turned off.\n");
}

// Function to dim light
void dim(int* lightStatus) {
    *lightStatus = DIM;
    printf("Light dimmed.\n");
}

// Function to brighten light
void brighten(int* lightStatus) {
    *lightStatus = BRIGHT;
    printf("Light brightened.\n");
}

int main() {
    // Initializing light status
    int livingRoomLight = OFF;
    int kitchenLight = OFF;
    
    // Displaying initial light status
    printStatus("Living room", livingRoomLight);
    printStatus("Kitchen", kitchenLight);
    
    // Turning on living room light
    turnOn(&livingRoomLight);
    
    // Dimming kitchen light
    dim(&kitchenLight);
    
    // Displaying updated light status
    printStatus("Living room", livingRoomLight);
    printStatus("Kitchen", kitchenLight);
    
    // Turning off living room light
    turnOff(&livingRoomLight);
    
    // Brightening kitchen light
    brighten(&kitchenLight);
    
    // Displaying final light status
    printStatus("Living room", livingRoomLight);
    printStatus("Kitchen", kitchenLight);
    
    return 0;
}