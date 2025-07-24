//FormAI DATASET v1.0 Category: Temperature monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random seed

    int temp = rand() % 101; //generate a random temperature between 0-100
    int minTemp = temp;
    int maxTemp = temp;
    int totalTemp = temp;
    int count = 1;

    printf("Welcome to the Retro Temperature Monitor!\n\n");

    //print the first day's temperature
    printf("Day %d: %d degrees Celsius\n", count, temp);

    while(count < 7) //monitor temperature for 7 days
    {
        temp = rand() % 101; //generate a random temperature between 0-100

        if(temp < minTemp) //update minimum temperature
        {
            minTemp = temp;
        }
        if(temp > maxTemp) //update maximum temperature
        {
            maxTemp = temp;
        }

        totalTemp += temp; //update total temperature
        count++; //increment the day

        printf("Day %d: %d degrees Celsius\n", count, temp); //print the day's temperature
    }

    //calculate and print average temperature
    double avgTemp = (double) totalTemp / 7;
    printf("\nAverage Temperature: %.2f degrees Celsius\n", avgTemp);

    //print minimum and maximum temperature
    printf("Minimum Temperature: %d degrees Celsius\n", minTemp);
    printf("Maximum Temperature: %d degrees Celsius\n", maxTemp);

    return 0;
}