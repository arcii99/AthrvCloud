//FormAI DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>

int main() {
    char given_unit;
    double given_temp, converted_temp;

    printf("Enter the temperature:\n");
    scanf("%lf", &given_temp);

    printf("Enter the unit of temperature (C/F/K):\n");
    scanf(" %c", &given_unit);

    if (given_unit == 'F') {
        converted_temp = (given_temp - 32.0) * 5.0 / 9.0;
        printf("%.1lf F = %.1lf C\n", given_temp, converted_temp);
    }
    else if (given_unit == 'C') {
        converted_temp = given_temp * 9.0 / 5.0 + 32.0;
        printf("%.1lf C = %.1lf F\n", given_temp, converted_temp);
    }
    else if (given_unit == 'K') {
        converted_temp = given_temp - 273.15;
        printf("%.1lf K = %.1lf C\n", given_temp, converted_temp);
    }
    else {
        printf("Invalid unit of temperature\n");
    }

    return 0;
}