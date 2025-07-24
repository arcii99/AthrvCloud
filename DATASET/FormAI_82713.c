//FormAI DATASET v1.0 Category: Temperature Converter ; Style: satisfied
#include <stdio.h>

int main() {
    float temperature, celsius, fahrenheit;
    int choice;
    
    printf("Temperature Converter\n");
    printf("---------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            fahrenheit = (temperature * 9.0/5.0) + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit", temperature, fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            celsius = (temperature - 32) * 5.0/9.0;
            printf("%.2f Fahrenheit is equal to %.2f Celsius", temperature, celsius);
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}