//FormAI DATASET v1.0 Category: Smart home automation ; Style: medieval
#include <stdio.h>

int main()
{
    int temperature, light;
    printf("Welcome to your medieval smart home automation system!\n");

    // Setting default temperature and light values
    temperature = 20;
    light = 1;
    printf("Current temperature is %d degrees Celsius.\n", temperature);
    printf("Lighting is %d.\n", light);

    // Temperature control
    printf("Do you wish to change the temperature? (0 for No, 1 for Yes): ");
    scanf("%d", &temperature);
    if (temperature == 1)
    {
        printf("Enter the temperature (in degrees Celsius): ");
        scanf("%d", &temperature);
        printf("New temperature is set to %d degrees Celsius.\n", temperature);
    }
    else
    {
        printf("Temperature remains at %d degrees Celsius.\n", temperature);
    }

    // Lighting control
    printf("Do you wish to turn off the lights? (0 for No, 1 for Yes): ");
    scanf("%d", &light);
    if (light == 1)
    {
        printf("Lights are turned off.\n");
    }
    else
    {
        printf("Lights are turned on.\n");
    }

    // Final confirmation
    printf("Temperature is set to %d degrees Celsius and lighting is %d.\n", temperature, light);
    printf("Thank you for using your medieval smart home automation system!\n");

    return 0;
}