//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int temperature, count = 0;
    double totalTemperature = 0;

    printf("Welcome to the Temperature Monitoring System\n");

    srand(time(0)); // Seed the random number generator with current time

    while(count < 10) 
    {
        temperature = (rand() % (100 - (-100) + 1)) - 100; // Generate a random number between -100 and 100
        totalTemperature += temperature; // Add the temperature to running total
        
        if(temperature < 0) 
        {
            printf("\nAlert! Temperature is below freezing point! Temperature recorded: %d\n", temperature);
            printf("Please ensure that you are wearing appropriate clothing and take necessary precautions!\n");
        }
        else if(temperature > 50) 
        {
            printf("\nAlert! Temperature is above permissible limit! Temperature recorded: %d\n", temperature);
            printf("Please take necessary steps to cool down and ensure that you do not over-exert yourself!\n");
        }
        else 
        {
            printf("\nTemperature recorded: %d\n", temperature);        
        }

        count++; // Increment the counter
        sleep(2); // Wait for 2 seconds before next reading
    }

    printf("\nAverage temperature recorded: %.2f\n", totalTemperature / count);
    printf("Thank you for using the Temperature Monitoring System!\n");

    return 0;
}