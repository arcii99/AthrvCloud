//FormAI DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>

void print_menu() {
    printf("Select conversion type:\n");
    printf("1 - Celsius to Fahrenheit\n");
    printf("2 - Fahrenheit to Celsius\n");
    printf("3 - Exit\n");
}

float to_fahrenheit(float celsius) {
    return celsius * 1.8 + 32;
}

float to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    int choice;
    float value, result;
    while (1) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Celsius value:\n");
                scanf("%f", &value);
                result = to_fahrenheit(value);
                printf("Result: %f Fahrenheit\n", result);
                break;
            case 2:
                printf("Enter Fahrenheit value:\n");
                scanf("%f", &value);
                result = to_celsius(value);
                printf("Result: %f Celsius\n", result);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}