//FormAI DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int current_temp = 25; // Starting temperature
    srand(time(0)); // Seed for random number generator
    int day = 1; // Starting day
    
    printf("Welcome to my weather simulation program!\n");
    printf("The current temperature is %d degrees Celsius.\n", current_temp);
    
    while (day <= 7) // Simulate weather for one week
    {
        int random_change = (rand() % 10) - 5; // Generate random number for temperature change between -5 and 5 degrees
        
        current_temp += random_change; // Update current temperature
        
        printf("\nDay %d:", day);
        
        if (random_change > 0) // Temperature increased
        {
            printf("\nThe temperature increased by %d degrees Celsius.", random_change);
        }
        else if (random_change < 0) // Temperature decreased
        {
            printf("\nThe temperature decreased by %d degrees Celsius.", -random_change);
        }
        else // Temperature did not change
        {
            printf("\nThe temperature did not change.");
        }
        
        printf("\nThe current temperature is %d degrees Celsius.", current_temp);
        
        day++; // Move to next day
    }
    
    printf("\n\nThank you for using my weather simulation program!");
    
    return 0;
}