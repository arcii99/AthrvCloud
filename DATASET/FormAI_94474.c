//FormAI DATASET v1.0 Category: Weather simulation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

#define ARRAY_LENGTH 365 // number of days in a year

// Function to get random temperature value between -20 and 50 degrees Celsius
float getTemperature()
{
    float temp = rand() % 70 - 20;
    return temp;
}

int main()
{
    float temperature[ARRAY_LENGTH]; //creating an array to hold temperature values for a year

    //filling the temperature array with random temperatures
    for(int i=0; i<ARRAY_LENGTH; i++)
    {
        temperature[i] = getTemperature();
    }

    //calculating and printing average temperature for each month
    for(int i=0; i<12; i++)
    {
        float sum = 0;
        int daysInMonth;

        //determining number of days in each month
        switch(i)
        {
            case 0: daysInMonth = 31;
                    break;
            case 1: daysInMonth = 28;
                    break;
            case 2: daysInMonth = 31;
                    break;
            case 3: daysInMonth = 30;
                    break;
            case 4: daysInMonth = 31;
                    break;
            case 5: daysInMonth = 30;
                    break;
            case 6: daysInMonth = 31;
                    break;
            case 7: daysInMonth = 31;
                    break;
            case 8: daysInMonth = 30;
                    break;
            case 9: daysInMonth = 31;
                    break;
            case 10: daysInMonth = 30;
                    break;
            case 11: daysInMonth = 31;
                    break;
        }

        //calculating sum of temperatures for each month
        for(int j=0; j<daysInMonth; j++)
        {
            sum += temperature[i*30+j];
        }

        //calculating average temperature for each month
        float avgTemp = sum/daysInMonth;

        //printing average temperature for each month
        printf("Average temperature for month %d is %.2f degrees Celsius\n", i+1, avgTemp);
    }

    return 0;
}