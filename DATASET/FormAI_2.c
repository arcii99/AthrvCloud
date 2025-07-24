//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: medieval
/*  Medieval Circuit Simulator
    This program simulates a simple electrical circuit consisting of three components:
    a battery, a resistor and a light bulb.
    It uses a medieval theme to make it more interesting.
*/

#include <stdio.h>

int main() {
    
    int battery_voltage = 10; // the voltage of the battery in volts
    int resistance = 5; // the resistance of the resistor in ohms
    int bulb_brightness = 0; // the brightness of the light bulb in lumens
    
    // print the circuit components
    printf("The circuit consists of a %d volt battery, a %d ohm resistor and a light bulb.\n\n", battery_voltage, resistance);
    
    // calculate the current flowing through the circuit
    int current = battery_voltage / resistance;
    
    // simulate the light bulb increasing in brightness as the current flows through it
    for(int i = 0; i < current; i++) {
        bulb_brightness += 5;
        printf("The %d lumen light bulb is now %d%% bright.\n", bulb_brightness, (bulb_brightness * 100) / 1000);
    }
    
    // print the final brightness of the light bulb
    printf("\nThe light bulb is now at %d lumens.\n", bulb_brightness);
    
    return 0;
}