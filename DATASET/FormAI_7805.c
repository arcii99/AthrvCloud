//FormAI DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Display welcome message
    printf("*** Temperature Converter ***\n");

    // Variables for user input and converted temperature
    double temp, converted_temp;
    char unit;

    // Prompt user for temperature
    printf("Enter temperature: ");
    scanf("%lf", &temp);

    // Prompt user for temperature unit
    printf("Enter unit (C/F): ");
    scanf(" %c", &unit);

    // Determine conversion factor based on temperature unit
    double factor;
    if (unit == 'F' || unit == 'f') {
        factor = 5.0 / 9.0;
    } else if (unit == 'C' || unit == 'c') {
        factor = 9.0 / 5.0;
    } else {
        printf("Invalid unit. Exiting program.\n");
        exit(0);
    }

    // Convert temperature and display result
    if (unit == 'F' || unit == 'f') {
        converted_temp = (temp - 32.0) * factor;
        printf("%0.2f%cF is equivalent to %0.2f%cC\n", temp, unit, converted_temp, 'C');
    } else if (unit == 'C' || unit == 'c') {
        converted_temp = (temp * factor) + 32.0;
        printf("%0.2f%cC is equivalent to %0.2f%cF\n", temp, unit, converted_temp, 'F');
    }

    return 0;
}