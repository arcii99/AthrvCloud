//FormAI DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>

int main()
{
    char unit;
    float temp, converted;

    printf("Please enter the temperature: ");
    scanf("%f", &temp);

    printf("Is the temperature in Celsius or Fahrenheit? Enter 'C' for Celsius or 'F' for Fahrenheit: ");
    scanf(" %c", &unit);

    if (unit == 'C' || unit == 'c') {
        converted = (temp * 9 / 5) + 32;
        printf("%.1f Celsius is equal to %.1f Fahrenheit\n", temp, converted);
    } else if (unit == 'F' || unit == 'f') {
        converted = (temp - 32) * 5 / 9;
        printf("%.1f Fahrenheit is equal to %.1f Celsius\n", temp, converted);
    } else {
        printf("Invalid unit entered\n");
    }

    return 0;
}