//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature;
    srand(time(NULL));
    int readings[10];
    int i = 0;

    while (i < 10) {
        temperature = ((float)rand()/(float)(RAND_MAX)) * 100 - 50; // Generate random temperature between -50 and 50 Celsius
        printf("Temperature reading: %0.2f C\n", temperature);
        if (temperature < 0) {
            printf("*WARNING* Temperature is below freezing point.\n");
        }
        readings[i] = temperature;
        i++;
    }

    float average = 0;
    for (int j = 0; j < 10; j++) {
        average += readings[j];
    }
    average /= 10;
    printf("\nAverage temperature over last 10 readings: %0.2f C\n", average);

    return 0;
}