//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    char choice;

    printf("Celsius to Fahrenheit converter\n");
    printf("Enter C to convert Celsius to Fahrenheit\n");
    printf("Enter F to convert Fahrenheit to Celsius\n");
    scanf("%c", &choice);
    fflush(stdin);

    if(choice == 'C' || choice == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        
        fahrenheit = (celsius * (9.0 / 5.0)) + 32.0;
        printf("%.2f°C = %.2f°F", celsius, fahrenheit);
    }
    else if(choice == 'F' || choice == 'f') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        
        celsius = (fahrenheit - 32.0) * (5.0 / 9.0);
        printf("%.2f°F = %.2f°C", fahrenheit, celsius);
    }
    else {
        printf("Invalid input\n");
    }

    return 0;
}