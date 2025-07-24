//FormAI DATASET v1.0 Category: Temperature Converter ; Style: innovative
#include <stdio.h>

int main() {
    float temperature, converted_temperature;
    char unit;

    // Ask user for input
    printf("Enter temperature: ");
    scanf("%f%c", &temperature, &unit);

    // Check if input unit is valid
    if (unit == 'C' || unit == 'c') {
        converted_temperature = (temperature * 9 / 5) + 32;
        printf("%.2fC is %.2fF\n", temperature, converted_temperature);
    } else if (unit == 'F' || unit == 'f') {
        converted_temperature = (temperature - 32) * 5 / 9;
        printf("%.2fF is %.2fC\n", temperature, converted_temperature);
    } else {
        printf("Invalid input unit\n");
        return 1;
    }

    return 0;
}