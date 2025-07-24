//FormAI DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>

int main() {
    float celsius, fahrenheit, kelvin;
    int menu_choice;
    
    printf("Select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    scanf("%d", &menu_choice);
    
    switch (menu_choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 1.8) + 32;
            printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit\n", celsius, fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) / 1.8;
            printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius\n", fahrenheit, celsius);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            kelvin = celsius + 273.15;
            printf("%.2f degree Celsius is equal to %.2f Kelvin\n", celsius, kelvin);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &kelvin);
            celsius = kelvin - 273.15;
            printf("%.2f Kelvin is equal to %.2f degree Celsius\n", kelvin, celsius);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            kelvin = (5 * (fahrenheit - 32) / 9) + 273.15;
            printf("%.2f degree Fahrenheit is equal to %.2f Kelvin\n", fahrenheit, kelvin);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &kelvin);
            fahrenheit = (9 * (kelvin - 273.15) / 5) + 32;
            printf("%.2f Kelvin is equal to %.2f degree Fahrenheit\n", kelvin, fahrenheit);
            break;
        default:
            printf("Invalid option");
            break;
    }
    
    return 0;
}