//FormAI DATASET v1.0 Category: Temperature monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temp, tempSum = 0, tempAvg;
    int i;
    srand(time(NULL));
 
    printf("Temperature Monitor\n");
    printf("-------------------\n");

    for (i = 1; i <= 100; i++)
    {
        temp = (float)(rand() % 201 - 100) / 10;
        tempSum += temp;
        printf("Temperature reading %d: %.1f degree Celsius\n", i, temp);
    }

    tempAvg = tempSum / 100;
    printf("-------------------\n");
    printf("Average temperature reading: %.1f degree Celsius\n", tempAvg);

    if (tempAvg >= 35.5 && tempAvg <= 37.5)
    {
        printf("The temperature is normal.\n");
    }
    else if (tempAvg < 35.5)
    {
        printf("The temperature is below normal.\n");
    }
    else
    {
        printf("The temperature is above normal.\n");
    }

    return 0;
}