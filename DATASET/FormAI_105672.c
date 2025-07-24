//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>

int main() {
    float temp_celsius, temp_fahrenheit;
    int choice;

    printf("Temperature Converter\n\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nEnter temperature in Celsius: ");
        scanf("%f", &temp_celsius);
        temp_fahrenheit = (temp_celsius * 9/5) + 32;
        printf("\n%.2f degree Celsius is equal to %.2f degree Fahrenheit\n",temp_celsius,temp_fahrenheit);
    }
    else if(choice == 2) {
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%f", &temp_fahrenheit);
        temp_celsius = (temp_fahrenheit - 32) * 5/9;
        printf("\n%.2f degree Fahrenheit is equal to %.2f degree Celsius\n",temp_fahrenheit,temp_celsius);
    }
    else {
        printf("\nInvalid choice! Please enter either 1 or 2\n");
    }

    return 0;
}