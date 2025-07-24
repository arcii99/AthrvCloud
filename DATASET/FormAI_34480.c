//FormAI DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include <stdio.h>

int main() {
    float temp, result;
    char type;

    printf("Enter the temperature value: ");
    scanf("%f", &temp);

    printf("Enter temperature type (C/F): ");
    scanf("%c", &type);
    scanf("%c", &type);

    if (type == 'C' || type == 'c') {
        result = (9 * temp) / 5 + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", temp, result);
    } else if (type == 'F' || type == 'f') {
        result = (temp - 32) * 5 / 9;
        printf("%.2f Fahrenheit = %.2f Celsius\n", temp, result);
    } else {
        printf("Invalid temperature type entered.\n");
    }

    return 0;
}