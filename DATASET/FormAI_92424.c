//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Donald Knuth
// Donald Knuth style C Temperature Converter

#include <stdio.h>

int main() {
    float temperature;
    char choice;

    printf("Temperature Converter\n");
    printf("Enter temperature: ");
    scanf("%f", &temperature);

    printf("Convert to [F]ahrenheit or [C]elsius? ");
    scanf(" %c", &choice);

    switch(choice) {
        case 'F':
        case 'f':
            temperature = (temperature * 1.8) + 32;
            printf("%.2f degree Celsius = %.2f degree Fahrenheit\n", temperature - 32 / 1.8, temperature);
            break;
        case 'C':
        case 'c':
            temperature = (temperature - 32) / 1.8;
            printf("%.2f degree Fahrenheit = %.2f degree Celsius\n", temperature * 1.8 + 32, temperature);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}