//FormAI DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    int option;

    printf("Enter 1 to convert Fahrenheit to Celsius\n");
    printf("Enter 2 to convert Celsius to Fahrenheit\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);

            celsius = (fahrenheit - 32) * 5/9;

            printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, celsius);
            break;

        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);

            fahrenheit = (celsius * 9/5) + 32;

            printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
            break;

        default:
            printf("Invalid option. Please enter either 1 or 2.\n");
            break;
    }

    return 0;
}