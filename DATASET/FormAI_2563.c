//FormAI DATASET v1.0 Category: Smart home automation ; Style: invasive
#include <stdio.h>
#include <stdbool.h>

// Function declarations
void light_control(bool);

int main()
{
    // Initialize sensor and actuator states
    bool temp_sensor = true;
    bool motion_sensor = false;
    bool door_sensor = false;
    bool light_status = false;

    // Check sensor states and take actions accordingly
    if(temp_sensor == true)
    {
        printf("Temperature is above normal. Turning on AC.\n");
    }
    else
    {
        printf("Temperature is normal. AC is turned off.\n");
    }

    if(motion_sensor == true)
    {
        printf("Motion detected. Turning on lights.\n");
        light_control(true);
        light_status = true;
    }
    else
    {
        printf("No motion detected. Turning off lights.\n");
        light_control(false);
        light_status = false;
    }

    if(door_sensor == true)
    {
        printf("Door is open. Sending notification to owner.\n");
    }
    else
    {
        printf("Door is closed. No action required.\n");
    }

    // End of program
    printf("Program execution completed.");

    return 0;
}

// Function definition for controlling lights
void light_control(bool status)
{
    if(status == true)
    {
        printf("Lights turned on.\n");
    }
    else
    {
        printf("Lights turned off.\n");
    }
}