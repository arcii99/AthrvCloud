//FormAI DATASET v1.0 Category: Temperature monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 200 // Maximum allowed temperature

int main(void)
{
    float temperature;
    char input[50];
    int i, temperature_int;
    
    printf("Enter temperature in Celsius: ");
    fgets(input, 50, stdin); // Get input from user

    // Check if input is valid
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            printf("Invalid input\n");
            return 1; // Return error status
        }
    }

    temperature_int = atoi(input);
    temperature = (float) temperature_int;

    if (temperature > MAX_TEMP)
    {
        printf("Temperature is too high\n");
        return 1; // Return error status
    }

    printf("Temperature: %.2f Celsius\n", temperature);

    return 0; // Return success status
}