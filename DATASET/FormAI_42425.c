//FormAI DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include<stdio.h>

int main(){
    // Print a welcome message
    printf("Welcome to the Temperature Converter!\n");
    
    // Prompt the user for input
    printf("Please enter a temperature in Celsius: ");
    float celsius;
    scanf("%f", &celsius);
    
    // Convert the temperature to Fahrenheit
    float fahrenheit = (celsius * 9/5) + 32;
    
    // Print the result
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
    
    // Prompt the user for more input
    printf("Would you like to convert another temperature? (Y/N): ");
    char choice;
    scanf(" %c", &choice);
    
    // Check the user's input and loop if necessary
    while(choice == 'Y' || choice == 'y') {
        printf("Please enter a temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9/5) + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
        printf("Would you like to convert another temperature? (Y/N): ");
        scanf(" %c", &choice);
    }
    
    // Exit the program
    printf("Thank you for using the Temperature Converter! Goodbye.");
    return 0;
}