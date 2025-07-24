//FormAI DATASET v1.0 Category: Smart home automation ; Style: Ada Lovelace
/* Smart Home Automation Example Program by Ada Lovelace */

#include <stdio.h>

typedef enum {OFF, ON} state_t; // define state enum for devices

struct device { // define device struct
    char *name;
    state_t state;
};

struct device livingroom_light = {"Living Room Light", OFF}; // create device structs
struct device kitchen_light = {"Kitchen Light", OFF};
struct device thermostat = {"Thermostat", OFF};

void print_device(struct device d) { // function to print device info
    printf("%s: %s\n", d.name, (d.state == ON) ? "ON" : "OFF");
}

int main() {
    printf("Welcome to Smart Home Automation!\n\n");
    
    print_device(livingroom_light); // print initial device states
    print_device(kitchen_light);
    print_device(thermostat);
    
    // simulate turning devices on/off
    livingroom_light.state = ON;
    kitchen_light.state = ON;
    thermostat.state = ON;
    
    printf("\nDevices turned ON:\n");
    print_device(livingroom_light);
    print_device(kitchen_light);
    print_device(thermostat);
    
    livingroom_light.state = OFF;
    kitchen_light.state = OFF;
    
    printf("\nLiving room and kitchen lights turned OFF:\n");
    print_device(livingroom_light);
    print_device(kitchen_light);
    print_device(thermostat);
    
    return 0; // end program
}