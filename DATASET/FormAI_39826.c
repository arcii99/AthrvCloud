//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>

int main() {
    char choice;
    float temperature, converted_temperature;
    
    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("a. Convert Celsius to Fahrenheit\n");
    printf("b. Convert Fahrenheit to Celsius\n");
    scanf("%c", &choice);
    
    if (choice == 'a') {
        printf("Great! Please enter the temperature in Celsius: ");
        scanf("%f", &temperature);
        converted_temperature = (temperature * 9 / 5) + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, converted_temperature);
    } else if (choice == 'b') {
        printf("Awesome! Please enter the temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        converted_temperature = (temperature - 32) * 5 / 9;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, converted_temperature);
    } else {
        printf("I'm sorry, that's an invalid option. Please try again.\n");
    }
    
    return 0;
}