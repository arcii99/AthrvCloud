//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    printf("Welcome to the Temperature Monitor Program! \n");
    printf("Press ctrl+c to exit at any time. \n\n");

    int temperature;

    //infinitely loop and monitor temperature every 5 seconds
    while (1)
    {
        temperature = rand() % 50;  //generate a random temperature between 0-50 degrees Celsius

        //display temperature and "Warning" message if temperature is above 40 degrees Celsius
        printf("Current temperature: %d degrees Celsius \n", temperature);
        if(temperature >= 40)
        {
            printf("Warning: High temperature detected! \n");
        }

        sleep(5); //wait for 5 seconds before monitoring the temperature again
    }

    return 0;
}