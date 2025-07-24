//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_DEVICES 5
#define MAX_SIGNAL_STRENGTH 100

// Custom struct for devices
typedef struct Device {
    char name[20];
    int signalStrength;
} Device;

// Function to generate random signal strength values
int generateSignalStrength() {
    return rand() % (MAX_SIGNAL_STRENGTH + 1);
}

int main() {
    srand(time(NULL));
    Device devices[NUM_DEVICES];
    char deviceNames[NUM_DEVICES][20] = {"Laptop", "Smartphone", "Tablet", "Smart TV", "Desktop"};

    // Generate devices with random signal strengths
    for(int i = 0; i < NUM_DEVICES; i++) {
        strcpy(devices[i].name, deviceNames[i]);
        devices[i].signalStrength = generateSignalStrength();
    }

    // Print out the devices and their signal strengths
    printf("Devices:\n");
    printf("==============================================\n");
    for(int i = 0; i < NUM_DEVICES; i++) {
        printf("%s\t\tSignal Strength: %d\n", devices[i].name, devices[i].signalStrength);
    }
    printf("==============================================\n");

    // Find device with the strongest signal strength
    int maxStrengthIndex = 0;
    for(int i = 1; i < NUM_DEVICES; i++) {
        if(devices[i].signalStrength > devices[maxStrengthIndex].signalStrength) {
            maxStrengthIndex = i;
        }
    }
    printf("Device with strongest signal strength: %s\n", devices[maxStrengthIndex].name);

    // Find the average signal strength of all devices
    double signalStrengthTotal = 0;
    for(int i = 0; i < NUM_DEVICES; i++) {
        signalStrengthTotal += devices[i].signalStrength;
    }
    double averageSignalStrength = signalStrengthTotal / NUM_DEVICES;
    printf("Average signal strength of all devices: %f\n", averageSignalStrength);

    return 0;
}