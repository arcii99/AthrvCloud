//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    int temperature, maxTemp = -1000, minTemp = 1000;
    float avgTemp, sum = 0.0;
    int count = 0;

    printf("Enter the temperature, or -999 to exit:\n");

    while (1) {
        scanf("%d", &temperature);
        if (temperature == -999) {
            break;
        }
        if (temperature > maxTemp) {
            maxTemp = temperature;
        }
        if (temperature < minTemp) {
            minTemp = temperature;
        }
        sum += temperature;
        count++;
    }

    if (count > 0) {
        avgTemp = sum / count;
    } else {
        avgTemp = 0.0;
    }

    printf("Maximum temperature is: %d\n", maxTemp);
    printf("Minimum temperature is: %d\n", minTemp);
    printf("Average temperature is: %.2f\n", avgTemp);

    return 0;
}