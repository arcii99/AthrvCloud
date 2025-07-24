//FormAI DATASET v1.0 Category: Smart home automation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Control devices function
void controlDevice(char* deviceName, int status)
{
    if(status == 1)
        printf("Turning on %s...\n", deviceName);
    else
        printf("Turning off %s...\n", deviceName);
}

int main()
{
    int motionSensorStatus = 0;
    int temperatureSensorValue = 25;
    int doorStatus = 0;
    
    // Checking motion sensor status
    if(motionSensorStatus == 1)
        controlDevice("Lights", 1);
    
    // Checking temperature sensor value
    if(temperatureSensorValue > 30)
        controlDevice("Air conditioner", 1);
    else if(temperatureSensorValue < 20)
        controlDevice("Heater", 1);
    else
        controlDevice("None", 0);
        
    // Checking door status
    if(doorStatus == 0)
        controlDevice("Lock", 1);
    else
        controlDevice("Unlock", 0);

    return 0;
}