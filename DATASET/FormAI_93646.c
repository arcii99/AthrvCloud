//FormAI DATASET v1.0 Category: Temperature monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void main() {

    float temperature;
    char unit;
    float celsius, fahrenheit;

    printf("Enter the measured temperature: ");
    scanf("%f %c", &temperature, &unit);

    switch(unit) {
        case 'C':
            celsius = temperature;
            fahrenheit = (celsius * 1.8) + 32;
            printf("%.1fC is equivalent to %.1fF", celsius, fahrenheit);
            break;

        case 'F':
            fahrenheit = temperature;
            celsius = (fahrenheit - 32) / 1.8;
            printf("%.1fF is equivalent to %.1fC", fahrenheit, celsius);
            break;

        default:
            printf("Invalid unit. Please enter the temperature followed by the unit (C or F).");
    }

    if(celsius >= 30) {
        printf("\nWarning: High temperature detected. Take necessary precautions.");
    }
    else if(celsius < 0) {
        printf("\nWarning: Low temperature detected. Ensure proper heating is provided.");
    }
    else {
        printf("\nNo critical temperature detected.");
    }
}