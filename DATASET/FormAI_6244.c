//FormAI DATASET v1.0 Category: Weather simulation ; Style: automated
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    int temp[24], i, j;
    srand(time(0)); //to generate different random numbers every time program runs
    printf("***********************************************\n");
    printf("************* WEATHER SIMULATION ****************\n");
    printf("***********************************************\n");
    printf("Temperatures for 24 Hours\n");
    printf("========================\n");
    for(i=0; i<24; i++)
    {
        temp[i] = (rand()%20) + 10; //range: 10-30
        printf("%02dH: %d Degree Celsius\n", i+1, temp[i]);
    }
    printf("========================\n");
    int highest = temp[0], lowest = temp[0], avg = 0;
    for(j=0; j<24; j++)
    {
        if(temp[j] > highest)
            highest = temp[j];
        if(temp[j] < lowest)
            lowest = temp[j];
        avg += temp[j];
    }
    avg = avg/24;
    printf("\nHighest Temperature: %d Degree Celsius\n", highest);
    printf("Lowest Temperature: %d Degree Celsius\n", lowest);
    printf("Average Temperature: %d Degree Celsius\n", avg);

    if(avg >= 25)
    {
        printf("\nWeather is too hot..!!\n");
        printf("Please stay hydrated\n");
    }
    else if(avg >= 15)
    {
        printf("\nWeather is pleasant..!!\n");
        printf("Enjoy your day\n");
    }
    else
    {
        printf("\nWeather is too cold..!!\n");
        printf("Stay Warm\n");
    }

    return 0;
}