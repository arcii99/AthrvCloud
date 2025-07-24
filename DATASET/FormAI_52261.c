//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>

int main() {
    float cel, fahr, kelvin;
    int choice;
    printf("Welcome to the Temperature Converter App\n");
    printf("Please choose your input unit:\n1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &cel);
            fahr = (1.8 * cel) + 32;
            kelvin = cel + 273.15;
            printf("%.2fC = %.2fF\n%.2fC = %.2fK\n", cel, fahr, cel, kelvin);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahr);
            cel = (fahr - 32) / 1.8;
            kelvin = cel + 273.15;
            printf("%.2fF = %.2fC\n%.2fF = %.2fK\n", fahr, cel, fahr, kelvin);
            break;
        case 3:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &kelvin);
            cel = kelvin - 273.15;
            fahr = (1.8 * cel) + 32;
            printf("%.2fK = %.2fC\n%.2fK = %.2fF\n", kelvin, cel, kelvin, fahr);
            break;
        default:
            printf("Invalid choice");
    }
    return 0;
}