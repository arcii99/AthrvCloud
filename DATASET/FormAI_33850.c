//FormAI DATASET v1.0 Category: Weather simulation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int min_temp = -10, max_temp = 40;
    int days, hours, temperature;
    srand(time(NULL)); //Seed for random temperature
    printf("Enter the number of days you want to simulate: ");
    scanf("%d", &days);

    for(int i=1; i<=days; i++) //Loop for each day
    {
        printf("Day %d\n", i);
        for(int j=0; j<24; j++) //Loop for each hour in the day
        {
            temperature = (rand() % (max_temp - min_temp + 1)) + min_temp;
            printf("Hour %d: Temperature %dC\n", j, temperature);
        }
        printf("\n");
    }
    return 0;
}