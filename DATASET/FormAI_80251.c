//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option;
    double value;
    printf("Welcome to the Unit Converter!\n");
    printf("==============================\n");
    printf("Please choose an option from the following:\n");
    printf("1. Centimeters to Inches\n");
    printf("2. Inches to Centimeters\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Pounds to Kilograms\n");
    printf("Option: ");
    scanf("%d", &option);
    printf("Please enter the value to be converted: ");
    scanf("%lf", &value);
    
    switch(option) {
        case 1: {
            double result = value / 2.54;
            printf("%lf cm is equal to %lf inches\n", value, result);
            break;
        }
        case 2: {
            double result = value * 2.54;
            printf("%lf inches is equal to %lf cm\n", value, result);
            break;
        }
        case 3: {
            double result = value * 2.20462;
            printf("%lf kg is equal to %lf pounds\n", value, result);
            break;
        }
        case 4: {
            double result = value / 2.20462;
            printf("%lf pounds is equal to %lf kg\n", value, result);
            break;
        }
        default:
            printf("Invalid option selected. Please try again.\n");
            exit(1);
    }
    
    return 0;
}