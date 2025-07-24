//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float temp[10] = {28.5, 30.0, 32.6, 35.2, 36.8, 38.4, 40.0, 42.2, 44.5, 46.8};
    int i, j, n;

    printf("Enter the number of temperature readings:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Temperature reading %d: %.2f\n", i+1, temp[i]);
    }

    float maxTemp = temp[0];
    for(i = 1; i < n; i++)
    {
        if(maxTemp < temp[i])
        {
            maxTemp = temp[i];
        }
    }
    printf("\nMaximum temperature: %.2f\n", maxTemp);

    float minTemp = temp[0];
    for(i = 1; i < n; i++)
    {
        if(minTemp > temp[i])
        {
            minTemp = temp[i];
        }
    }
    printf("\nMinimum temperature: %.2f\n", minTemp);

    float avgTemp, totalTemp = 0.0;
    for(i = 0; i < n; i++)
    {
        totalTemp += temp[i];
    }
    avgTemp = totalTemp / n;
    printf("\nAverage temperature: %.2f\n", avgTemp);

    return 0;
}