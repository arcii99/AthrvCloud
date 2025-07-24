//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    double temperature, minTemp = 0, maxTemp = 0;
    int counter = 0;
    printf("Please input the current room temperature:\n");
    scanf("%lf", &temperature);
    minTemp = temperature;
    maxTemp = temperature;
    counter++;
    printf("Temperature recorded: %.2lf\n", temperature);
    while (1) {
        printf("Please input the current temperature again (-999 to terminate the program):\n");
        scanf("%lf", &temperature);
        if (temperature == -999) {
            printf("Exiting program...\n");
            break;
        }
        if (temperature > maxTemp) {
            maxTemp = temperature;
        }
        if (temperature < minTemp) {
            minTemp = temperature;
        }
        counter++;
        printf("Temperature recorded: %.2lf\n", temperature);
    }
    printf("Minimum temperature recorded: %.2lf\n", minTemp);
    printf("Maximum temperature recorded: %.2lf\n", maxTemp);
    printf("Average temperature recorded: %.2lf\n", (minTemp + maxTemp) / 2);
    printf("Total number of temperature readings: %d\n", counter);
    return 0;
}