//FormAI DATASET v1.0 Category: Unit converter ; Style: Donald Knuth
#include <stdio.h>

void to_celsius(float temp);
void to_fahrenheit(float temp);

int main() {
    int option;
    float temp;

    printf("Enter the temperature: ");
    scanf("%f", &temp);

    printf("Choose an option to convert:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            to_celsius(temp);
            break;
        case 2:
            to_fahrenheit(temp);
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}

void to_celsius(float temp) {
    float celsius = (temp - 32) * 5 / 9;
    printf("%.2f F = %.2f C\n", temp, celsius);
}

void to_fahrenheit(float temp) {
    float fahrenheit = (temp * 9 / 5) + 32;
    printf("%.2f C = %.2f F\n", temp, fahrenheit);
}