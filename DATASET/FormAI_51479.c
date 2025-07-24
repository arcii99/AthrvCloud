//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>

int main() {

    char choice;
    float temperature;

    printf("Welcome to Temperature Converter!\n");
    printf("Do you want to convert Celsius (C) or Fahrenheit (F)?\n");
    scanf("%c", &choice);

    if (choice == 'C' || choice == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        printf("%.2f Celsius = %.2f Fahrenheit", temperature, (temperature * 1.8) + 32);
    }
    else if (choice == 'F' || choice == 'f') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        printf("%.2f Fahrenheit = %.2f Celsius", temperature, (temperature - 32) / 1.8);
    }
    else {
        printf("Invalid choice");
    }

    return 0;
}