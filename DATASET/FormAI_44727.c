//FormAI DATASET v1.0 Category: Smart home automation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initializing variables
    int temp, hum;
    char pir, door;

    // Getting input from the sensors
    printf("Enter the temperature value: ");
    scanf("%d", &temp);
    printf("Enter the humidity value: ");
    scanf("%d", &hum);
    printf("Is there any movement detected? (Y/N): ");
    scanf(" %c", &pir);
    printf("Is the door open or closed? (O/C): ");
    scanf(" %c", &door);

    // Checking the input and taking action accordingly
    if(temp > 25 && hum > 70)
    {
        printf("It's too hot and humid! Turning on the AC.\n");
    }
    else if(temp < 20 && hum < 40)
    {
        printf("It's too cold and dry! Turning on the heater.\n");
    }

    if(pir == 'Y')
    {
        printf("Intruder alert! Turning on the siren.\n");
    }

    if(door == 'O')
    {
        printf("Door is open! Turning on the lights.\n");
    }

    return 0;
}