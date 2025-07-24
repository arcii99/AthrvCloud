//FormAI DATASET v1.0 Category: Temperature monitor ; Style: detailed
#include <stdio.h>

int main() {
    float temp[10], avg, sum = 0;
    int i;

    printf("Please enter 10 temperature values in degrees Celsius:\n");

    for (i = 0; i < 10; i++) {
        scanf("%f", &temp[i]);
        sum += temp[i]; // Add the temperature to the sum
    }

    // Calculate the average temperature
    avg = sum / 10;

    printf("The average temperature is %.2f degrees Celsius.\n", avg);

    // Check if any temperature exceeds the average
    for (i = 0; i < 10; i++) {
        if (temp[i] > avg) {
            printf("Temperature %.2f exceeds the average temperature.\n", temp[i]);
        }
    }

    return 0;
}