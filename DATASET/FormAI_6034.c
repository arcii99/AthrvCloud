//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>

int main() {
    printf("Welcome to the Temperature Converter!\n");
    printf("Enter the temperature in Celsius: ");
    
    float celsius, fahrenheit;
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 9 / 5) + 32;
    
    printf("%0.2f degrees Celsius is equal to %0.2f degrees Fahrenheit.\n", celsius, fahrenheit);
    printf("Would you like to convert another temperature? (Y/N) ");
    
    char choice;
    scanf(" %c", &choice);
    
    while (choice == 'Y' || choice == 'y') {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("%0.2f degrees Celsius is equal to %0.2f degrees Fahrenheit.\n", celsius, fahrenheit);
        printf("Would you like to convert another temperature? (Y/N) ");
        scanf(" %c", &choice);
    }
    
    printf("Thank you for using the Temperature Converter!");
    
    return 0;
}