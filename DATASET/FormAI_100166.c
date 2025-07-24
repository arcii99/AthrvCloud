//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Donald Knuth
#include <stdio.h>

int main() {
    float temperature[50];
    int i, count = 0;
    float sum = 0, average;

    /* Get temperature readings from user */
    for (i = 0; i < 50; i++) {
        printf("Enter temperature reading #%d: ", i+1);
        scanf("%f", &temperature[i]);

        /* Check for invalid input */
        while (temperature[i] < -50 || temperature[i] > 50) {
            printf("Invalid input. Please enter a temperature between -50 and 50: ");
            scanf("%f", &temperature[i]);
        }
    }

    /* Calculate the average temperature */
    for (i = 0; i < 50; i++) {
        sum += temperature[i];
    }
    average = sum / 50;

    /* Print out the temperature readings */
    printf("\nTemperature readings:\n");
    for (i = 0; i < 50; i++) {
        printf("%.2f ", temperature[i]);
        if (temperature[i] > average)
            count++;
    }

    /* Print out the average temperature and number of readings above average */
    printf("\n\nAverage temperature: %.2f", average);
    printf("\nNumber of readings above average: %d\n", count);

    return 0;
}