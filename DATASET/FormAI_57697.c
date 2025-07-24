//FormAI DATASET v1.0 Category: Temperature monitor ; Style: careful
#include <stdio.h>

int main() {
    float temperature;
    int upper_threshold = 30, lower_threshold = 15;

    printf("-----Temperature Monitor-----\n");

    while (1) {
        printf("Enter current temperature: ");
        scanf("%f", &temperature);

        if (temperature >= upper_threshold) {
            printf("Temperature is too high! Alert!\n");
        } else if (temperature <= lower_threshold) {
            printf("Temperature is too low! Alert!\n");
        } else {
            printf("Temperature is normal.\n");
        }
    }

    return 0;
}