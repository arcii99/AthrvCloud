//FormAI DATASET v1.0 Category: Temperature monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temp;   
    srand(time(NULL));  // seed for temperature generation
    
    printf("Welcome to the C Temperature Monitor!\n");
    printf("Generating random temperature values...\n");
    
    for(int i = 1; i <= 50; i++) // loop for generating 50 temperature values
    {
        temp = (rand() % 50) + 10; // generating a temperature between 10 to 60 degrees Celsius
        printf("Temperature value %d: %d degrees Celsius\n", i, temp);
        
        if(temp > 30) // checking if the temperature is above 30 degrees Celsius
        {
            printf("*** ALERT! High temperature detected! ***\n");
        }
        
        printf("--------------------------------------------\n");
    }
    
    printf("Temperature monitoring completed successfully.\n");
    return 0;
}