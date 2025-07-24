//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temp; // Declare temperature variable
    srand(time(NULL)); // Seed random number generator with current time
    
    // Print header
    printf("******************************\n");
    printf("Temperature Monitor\n");
    printf("******************************\n\n");
    
    // Loop to generate random temperatures and display
    for(int i = 0; i < 10; i++)
    {
        temp = (float)(rand() % 101) - 50; // Generate random temperature between -50°C and 50°C
        // Display temperature with appropriate sign
        if(temp < 0)
        {
            printf("Temperature #%d: %.2f°C\n", i+1, temp);
        }
        else
        {
            printf("Temperature #%d: +%.2f°C\n", i+1, temp);
        }
    }
    
    printf("\n\n"); // Add some space
    
    // Loop to prompt user for temperature input and display
    for(int i = 0; i < 3; i++)
    {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);
        printf("You entered: %.2f°C\n", temp);
    }
    
    return 0; // End program
}