//FormAI DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>

int main() {
    float temperature;
    char choice;

    printf("Welcome to Paranoid Temperature Converter\n\n");
    
    do {
        printf("\n\nPlease select your choice:\n");
        printf("C or c : Convert Celsius to Fahrenheit\n");
        printf("F or f : Convert Fahrenheit to Celsius\n");
        printf("Q or q : Quit\n");
        scanf(" %c", &choice);
        
        if (choice == 'C' || choice == 'c') {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            if (temperature <= -273.15) {
                printf("Temperature cannot be less than -273.15C. That's Absolute Zero!");
            } else {
                printf("%.2fC = %.2fF", temperature, (temperature * 9/5) + 32);
            }
        } else if (choice == 'F' || choice == 'f') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            if (temperature <= -459.67) {
                printf("Temperature cannot be less than -459.67F. That's Absolute Zero!");
            } else {
                printf("%.2fF = %.2fC", temperature, (temperature - 32) * 5/9);
            }
        } else if (choice == 'Q' || choice == 'q') {
            printf("Thank you for using Paranoid Temperature Converter!");
            return 0;
        } else {
            printf("Invalid choice. Please try again!");
        }
    } while (1);
    
    return 0;
}