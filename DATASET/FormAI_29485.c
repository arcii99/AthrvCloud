//FormAI DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>

int main() {
    int option;
    double input, output;

    printf("Welcome to the Unit Converter!\n");
    printf("Select an option: \n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Miles to Kilometres\n");
    printf("3. Pounds to Kilograms\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("\nEnter temperature in Celsius: ");
            scanf("%lf", &input);
            output = (input * 9/5) + 32;  // Conversion formula
            printf("%.2lf Celsius equals %.2lf Fahrenheit\n", input, output);
            break;
        case 2:
            printf("\nEnter distance in Miles: ");
            scanf("%lf", &input);
            output = input * 1.60934;  // Conversion formula
            printf("%.2lf Miles equals %.2lf Kilometres\n", input, output);
            break;
        case 3:
            printf("\nEnter weight in Pounds: ");
            scanf("%lf", &input);
            output = input * 0.453592;  // Conversion formula
            printf("%.2lf Pounds equals %.2lf Kilograms\n", input, output);
            break;
        default:
            printf("Invalid option. Please try again.\n");
            break;
    }

    return 0;
}