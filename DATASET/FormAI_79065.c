//FormAI DATASET v1.0 Category: Smart home automation ; Style: authentic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define the smart home automation system
typedef struct SmartHomeAutomation {
    bool isLampOn;
    bool isACOn;
    float temperature;
} SmartHomeAutomation;

// Declare function prototypes
void printCurrentStatus(SmartHomeAutomation);
void turnOnLamp(SmartHomeAutomation*);
void turnOffLamp(SmartHomeAutomation*);
void turnOnAC(SmartHomeAutomation*);
void turnOffAC(SmartHomeAutomation*);
void setTemperature(SmartHomeAutomation*, float);

// Main function
int main() {
    // Initialize the smart home automation system
    SmartHomeAutomation home = {false, false, 25.0};
    
    // Print the current status
    printCurrentStatus(home);
    
    // Turn on the lamp
    turnOnLamp(&home);
    
    // Set the temperature to 20 degrees Celsius
    setTemperature(&home, 20.0);
    
    // Turn on the AC
    turnOnAC(&home);
    
    // Print the current status
    printCurrentStatus(home);
    
    // Turn off the lamp
    turnOffLamp(&home);
    
    // Set the temperature to 30 degrees Celsius
    setTemperature(&home, 30.0);
    
    // Turn off the AC
    turnOffAC(&home);
    
    // Print the current status
    printCurrentStatus(home);
    
    return 0;
}

// Define functions
void printCurrentStatus(SmartHomeAutomation home) {
    printf("Current status:\n");
    if (home.isLampOn) {
        printf("The lamp is on.\n");
    } else {
        printf("The lamp is off.\n");
    }
    if (home.isACOn) {
        printf("The AC is on and the temperature is set to %.1f degrees Celsius.\n", home.temperature);
    } else {
        printf("The AC is off.\n");
    }
}

void turnOnLamp(SmartHomeAutomation *home) {
    home->isLampOn = true;
    printf("The lamp is now on.\n");
}

void turnOffLamp(SmartHomeAutomation *home) {
    home->isLampOn = false;
    printf("The lamp is now off.\n");
}

void turnOnAC(SmartHomeAutomation *home) {
    home->isACOn = true;
    printf("The AC is now on.\n");
}

void turnOffAC(SmartHomeAutomation *home) {
    home->isACOn = false;
    printf("The AC is now off.\n");
}

void setTemperature(SmartHomeAutomation *home, float temperature) {
    home->temperature = temperature;
    printf("The temperature has been set to %.1f degrees Celsius.\n", temperature);
}