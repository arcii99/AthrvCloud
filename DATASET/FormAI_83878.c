//FormAI DATASET v1.0 Category: Temperature monitor ; Style: authentic
#include <stdio.h>

int main() {
    float temp, minTemp = 100.0, maxTemp = -100.0, sum = 0.0;
    int count = 0;

    printf("Enter temperature values:\n");

    while (scanf("%f", &temp) == 1) {
        if (temp < -273.15) {
            printf("WARNING: Temperature is below absolute zero!\n");
            continue;
        }
        count++;
        sum += temp;

        if (temp > maxTemp) {
            maxTemp = temp;
        }
        if (temp < minTemp) {
            minTemp = temp;
        }
    }

    if (count == 0) {
        printf("No temperature values were entered.\n");
    } else {
        printf("%d temperature values were entered.\n", count);
        printf("Minimum temperature: %.2f\n", minTemp);
        printf("Maximum temperature: %.2f\n", maxTemp);
        printf("Average temperature: %.2f\n", sum / count);
    }

    return 0;
}