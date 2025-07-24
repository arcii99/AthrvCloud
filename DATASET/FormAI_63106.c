//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int temperature = 0;
    char temperature_unit = '\0';
    bool is_fahrenheit = false;

    while (true) {
        printf("Enter temperature: ");
        scanf("%d %c", &temperature, &temperature_unit);

        if (temperature_unit == 'F') {
            is_fahrenheit = true;
        } else if (temperature_unit == 'C') {
            is_fahrenheit = false;
        } else {
            printf("Invalid temperature unit. Please enter F or C.\n");
            continue;
        }

        if (is_fahrenheit) {
            temperature = (temperature - 32) * 5 / 9; // convert to Celsius
            printf("Temperature in Celsius: %dC\n", temperature);
        }

        if (temperature < 0) {
            printf("Warning: Temperature approaching freezing point. Make sure to keep warm.\n");
            continue;
        } else if (temperature > 40) {
            printf("Warning: Temperature approaching dangerous levels. Seek shelter and cool down.\n");
            continue;
        } else {
            printf("Temperature within safe levels.\n");
            continue;
        }
    }

    return 0;
}