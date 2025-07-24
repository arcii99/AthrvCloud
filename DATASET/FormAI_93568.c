//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Temperature Monitor Program!\n");

    float temp = 0.0;
    int count = 0;
    float sum = 0.0;

    while(1) {
        printf("Enter temperature reading: ");
        scanf("%f", &temp);

        if (temp == -1) {
            printf("End of temperature readings\n");
            break;
        }

        if (temp < -273.15) {
            printf("Invalid temperature: below absolute zero.\n");
            continue;
        }

        sum += temp;
        count++;

        printf("Temperature reading #%d: %.2f\n", count, temp);
    }

    if (count > 0) {
        float average = sum / count;
        printf("Average temperature: %.2f\n", average);
    } else {
        printf("No temperature readings to calculate average.\n");
    }

    return 0;
}