//FormAI DATASET v1.0 Category: Smart home automation ; Style: futuristic
/* Smart home automation program */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variables to store sensor data
    int temperature = 25;
    int humidity = 50;
    int lightIntensity = 100;

    // Variables to store user preferences
    int preferredTemperature = 22;
    int preferredHumidity = 60;
    int preferredLightIntensity = 70;

    // Check if temperature, humidity and light intensity are within user's preferred range
    if(temperature < preferredTemperature)
    {
        printf("Temperature is low. Turning on the heating system.\n");
        // Code to turn on heating system
    }
    else if(temperature > preferredTemperature)
    {
        printf("Temperature is high. Turning on the air conditioning.\n");
        // Code to turn on air conditioning
    }

    if(humidity < preferredHumidity)
    {
        printf("Humidity is low. Turning on the humidifier.\n");
        // Code to turn on the humidifier
    }
    else if(humidity > preferredHumidity)
    {
        printf("Humidity is high. Turning on the dehumidifier.\n");
        // Code to turn on the dehumidifier
    }

    if(lightIntensity < preferredLightIntensity)
    {
        printf("Light intensity is low. Turning on the lights.\n");
        // Code to turn on the lights
    }
    else if(lightIntensity > preferredLightIntensity)
    {
        printf("Light intensity is high. Turning off the lights.\n");
        // Code to turn off the lights
    }

    // Code to control other appliances like the TV and the washing machine based on user preferences

    return 0;
}