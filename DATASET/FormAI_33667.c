//FormAI DATASET v1.0 Category: Temperature Converter ; Style: peaceful
#include <stdio.h>

int main() {
    float temperature;
    int option;
    printf("Welcome to the Temperature Converter!\n\n");
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, (temperature * 9/5) + 32);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, (temperature - 32) * 5/9);
            break;
        default:
            printf("Invalid option, please select 1 or 2.\n");
    }
    return 0;
}