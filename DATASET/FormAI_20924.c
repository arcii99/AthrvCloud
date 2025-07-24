//FormAI DATASET v1.0 Category: Temperature monitor ; Style: lively
#include <stdio.h>

// function to check if temperature is in range
int checkTemperatureInRange(float temp)
{
    if(temp >= 0 && temp <= 100)
    {
        return 1; // temperature is within range
    }
    else
    {
        return 0; // temperature is out of range
    }
}

int main()
{
    float temperature;
    int inRange;

    printf("Welcome to the Temperature Monitor Program!\n");

    // get user input for temperature
    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &temperature);

    // check if temperature is within range
    inRange = checkTemperatureInRange(temperature);

    // if temperature is within range, display message saying so
    if(inRange == 1)
    {
        printf("The temperature is within range.\n");
    }
    // if temperature is out of range, display message saying so
    else
    {
        printf("The temperature is out of range.\n");
    }
    
    return 0;
}