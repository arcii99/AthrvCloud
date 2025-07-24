//FormAI DATASET v1.0 Category: Weather simulation ; Style: Alan Touring
/* C Weather Simulation Program */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int temperature[24], i, max=0, min=100, sum=0;
    float average=0.0;
    
    srand(time(0));
    
    printf("Daily temperature simulation for 24 hours\n\n");
    
    for(i=0; i<24; i++)
    {
        temperature[i] = (rand() % 51) + 10; // temperature ranges from 10 to 60 degrees Celsius
        printf("Hour %d: %d degree(s) Celsius\n", i+1, temperature[i]);
        sum += temperature[i];
        
        if(temperature[i] > max)
            max = temperature[i];
        
        if(temperature[i] < min)
            min = temperature[i];
    }
    
    average = (float) sum / 24;
    
    printf("\nMaximum temperature for the day: %d degree(s) Celsius\n", max);
    printf("Minimum temperature for the day: %d degree(s) Celsius\n", min);
    printf("Average temperature for the day: %.2f degree(s) Celsius\n\n", average);
    
    if(max > 30)
    {
        printf("WARNING: High temperature alert for the day!\n");
    }
    
    if(min < 10)
    {
        printf("WARNING: Low temperature alert for the day!\n");
    }
    
    return 0;
}