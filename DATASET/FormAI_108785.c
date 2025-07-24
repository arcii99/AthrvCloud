//FormAI DATASET v1.0 Category: Weather simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Seed for random number generator

    int temperature; //Declaring temperature variable
    
    printf("Welcome to Weather Simulator!\n");

    printf("Enter the starting temperature: ");
    scanf("%d",&temperature); //Getting input from user for starting temperature
    
    printf("\n");

    printf("The current temperature is: %d degrees Celsius.\n",temperature);

    for(int i = 1; i <= 7; i++) //Loop for simulating one week of weather
    {
        int change = (rand() % 21) - 10; //Generating a random number between -10 and 10

        temperature += change; //Adding change to temperature

        if (temperature < -30 || temperature > 50) //Checking if temperature becomes too high or too low
        {
            printf("Extreme weather condition detected! Simulation stopped.\n");
            break;
        }

        printf("Day %d temperature: %d degrees Celsius\n",i,temperature);
    }

    printf("\n");

    printf("End of weather simulation. Thank you for using Weather Simulator!\n");

    return 0;
}