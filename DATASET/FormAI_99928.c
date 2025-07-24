//FormAI DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>

int main() {
    // A futuristic program to manipulate bits to control a spaceship

    // Variable declarations
    unsigned int status = 0b00000000; // status of spaceship in binary 0b format
    unsigned int power = 0b10000000; // power status in binary 0b format
    unsigned int communication = 0b01000000; // communication status in binary 0b format
    unsigned int navigation = 0b00100000; // navigation status in binary 0b format
    unsigned int fuel = 0b00010000; // fuel status in binary 0b format
    unsigned int oxygen = 0b00001000; // oxygen status in binary 0b format
    unsigned int temperature = 0b00000100; // temperature status in binary 0b format
    unsigned int pressure = 0b00000010; // pressure status in binary 0b format

    // Setting some initial status for the spaceship
    status |= power; // power on
    status |= communication; // communication active
    status |= fuel; // fuel present
    status |= oxygen; // oxygen present

    // Printing initial status
    printf("Initial status: %d\n", status);

    // Bitwise operations to manipulate status

    // Disable navigation
    status &= ~navigation;

    // Increase temperature
    status |= temperature;

    // Decrease pressure
    status ^= pressure;

    // Print status after manipulation
    printf("Status after manipulation: %d\n", status);

    // Checking status of individual components using bitwise AND operation

    // Checking if power is on
    if (status & power) {
        printf("Power is on\n");
    } else {
        printf("Power is off\n");
    }

    // Checking if communication is active
    if (status & communication) {
        printf("Communication is active\n");
    } else {
        printf("Communication is inactive\n");
    }

    // Checking fuel level
    if (status & fuel) {
        printf("Fuel is present\n");
    } else {
        printf("Fuel is empty\n");
    }

    // Checking oxygen level
    if (status & oxygen) {
        printf("Oxygen is present\n");
    } else {
        printf("Oxygen is empty\n");
    }

    // Checking navigation status
    if (status & navigation) {
        printf("Navigation is active\n");
    } else {
        printf("Navigation is disabled\n");
    }

    // Checking temperature status
    if (status & temperature) {
        printf("Temperature is high\n");
    } else {
        printf("Temperature is normal\n");
    }

    // Checking pressure status
    if (status & pressure) {
        printf("Pressure is low\n");
    } else {
        printf("Pressure is normal\n");
    }

    return 0;
}