//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>

int main() {
    float temperature, converted_temp;
    char choice;

    printf("Enter temperature: ");
    scanf("%f", &temperature);

    printf("Enter input scale (C or F): ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'C':
        case 'c':
            converted_temp = (9 * temperature / 5) + 32;
            printf("%.2f degrees Celsius = %.2f degrees Fahrenheit\n", temperature, converted_temp);
            break;
        
        case 'F':
        case 'f':
            converted_temp = (temperature - 32) * 5 / 9;
            printf("%.2f degrees Fahrenheit = %.2f degrees Celsius\n", temperature, converted_temp);
            break;

        default:
            printf("Invalid input scale");
            break;
    }

    return 0;
}