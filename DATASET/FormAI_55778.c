//FormAI DATASET v1.0 Category: Temperature Converter ; Style: relaxed
#include <stdio.h>

int main() {
    char choice;
    float cel, fahr;
    
    printf("Hello, welcome to the Temperature Converter!\n");
    printf("Enter 'C' to convert Celsius to Fahrenheit\n");
    printf("Enter 'F' to convert Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);
    getchar(); //getchar to clear the input buffer
    
    if (choice == 'C' || choice == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &cel);
        fahr = (cel * 9/5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", cel, fahr);
    }
    else if (choice == 'F' || choice == 'f') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahr);
        cel = (fahr - 32) * 5/9;
        printf("%.2f Fahrenheit = %.2f Celsius\n", fahr, cel);
    }
    else {
        printf("Invalid choice, please enter 'C' or 'F'\n");
    }
    
    printf("Thank you for using the Temperature Converter! Goodbye.\n");
    return 0;
}