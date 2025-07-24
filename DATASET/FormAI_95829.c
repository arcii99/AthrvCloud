//FormAI DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>

int main() {
    int choice;
    float temperature, result;
    printf("Choose any one of the below conversions:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            result = (temperature * 9/5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit", temperature, result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            result = (temperature - 32) * 5/9;
            printf("%.2f Fahrenheit = %.2f Celsius", temperature, result);
            break;
        default:
            printf("Invalid choice!");
            break;
    }
    return 0;
}