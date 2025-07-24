//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    float temperature;
    printf("\nWelcome to the Temperature Monitor System \n");

    srand(time(NULL));
    int temp_values[10];
    for(int i=0;i<10;i++)
    {
        temp_values[i] = rand()%20 + 10;
    }

    printf("\nTemperature Monitor initialized...\n");

    for(int i=0;i<10;i++)
    {
        temperature = temp_values[i];
        if(temperature > 30.0)
        {
            printf("\nALERT! Temperature is above the threshold limit!!\n");
        }
        printf("\nTemperature Value : %.2f\n", temperature);
    }
    return 0;
}