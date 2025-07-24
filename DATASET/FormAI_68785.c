//FormAI DATASET v1.0 Category: Temperature Converter ; Style: thoughtful
#include<stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    do {
        printf("\nChoose an option:\n1. Celsius to Fahrenheit Conversion\n2. Fahrenheit to Celsius Conversion\n3. Exit\n");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 9/5) + 32;
                printf("Temperature in Fahrenheit: %0.2f\n", fahrenheit);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) * 5/9;
                printf("Temperature in Celsius: %0.2f\n", celsius);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}