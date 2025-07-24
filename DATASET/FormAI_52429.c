//FormAI DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>

int main() {
    float f_temperature, c_temperature;
    int choice;

    printf("Welcome to the Temperature Converter");

    while(1) {
        printf("\n\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Exit\n");
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &f_temperature);
                c_temperature = (f_temperature - 32) * 5/9;
                printf("\nThe temperature in Celsius is %.2f", c_temperature);
                break;

            case 2:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &c_temperature);
                f_temperature = (c_temperature * 9/5) + 32;
                printf("\nThe temperature in Fahrenheit is %.2f", f_temperature);
                break;

            case 3:
                printf("\nThank you for using the Temperature Converter.");
                exit(0);

            default:
                printf("\nInvalid choice. Please choose again.");
        }
    }

    return 0;
}