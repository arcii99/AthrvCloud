//FormAI DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>

// Function Declarations
double convertToCelsius(double temp, char unit);
double convertToFahrenheit(double temp, char unit);

// Main Function
int main(void) {
    double temp;
    char unit;
    printf("Enter temperature to convert: ");
    scanf("%lf%c", &temp, &unit);

    if (unit == 'C' || unit == 'c') {
        printf("%.2lfC = %.2lfF\n", temp, convertToFahrenheit(temp, 'C'));
    } else if (unit == 'F' || unit == 'f') {
        printf("%.2lfF = %.2lfC\n", temp, convertToCelsius(temp, 'F'));
    } else {
        printf("Invalid input! Please enter in format of '1 C' or '1 F'");
        return 0;
    }

    return 0;
}

// Function Definitions
double convertToCelsius(double temp, char unit) {
    if (unit == 'F' || unit == 'f') {
        return (temp - 32) * 5 / 9;
    } else {
        return temp;
    }
}

double convertToFahrenheit(double temp, char unit) {
    if (unit == 'C' || unit == 'c') {
        return (temp * 9 / 5) + 32;
    } else {
        return temp;
    }
}