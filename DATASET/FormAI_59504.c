//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>

int main() {
    int choice;
    float input, output;
    printf("Welcome to Unit Converter!\n");
    printf("Select an option:\n");
    printf("[1] Celsius to Fahrenheit\n");
    printf("[2] Feet to Meters\n");
    printf("[3] US Gallons to Liters\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a temperature in Celsius: ");
            scanf("%f", &input);
            output = (input * 9 / 5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", input, output);
            break;
        case 2:
            printf("Enter a length in feet: ");
            scanf("%f", &input);
            output = input / 3.281;
            printf("%.2f feet = %.2f meters\n", input, output);
            break;
        case 3:
            printf("Enter a volume in US gallons: ");
            scanf("%f", &input);
            output = input * 3.785;
            printf("%.2f gallons = %.2f liters\n", input, output);
            break;
        default:
            printf("Invalid option!\n");
            break;
    }

    return 0;
}