//FormAI DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>

int main() {
    int option;         // To keep track of the conversion option
    float temp;         // To keep the temperature entered by the user
    float convertedTemp;    // To store the converted temperature
    
    // Prompt the user to choose the temperature conversion option
    printf("Choose an option:\n");
    printf("1. Celsius to Fahrenheit.\n");
    printf("2. Fahrenheit to Celsius.\n");
    scanf("%d", &option);
    
    // Check if the option entered by the user is valid
    if (option != 1 && option != 2) {
        printf("Invalid option.\n");
        return 0;
    }
    
    // Prompt the user to enter the temperature to convert
    printf("Enter the temperature to convert: ");
    scanf("%f", &temp);
    
    // Perform the temperature conversion based on the option selected
    if (option == 1) {
        // Convert Celsius to Fahrenheit
        convertedTemp = temp * 1.8 + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", temp, convertedTemp);
    } else if (option == 2) {
        // Convert Fahrenheit to Celsius
        convertedTemp = (temp - 32) / 1.8;
        printf("%.2f Fahrenheit = %.2f Celsius\n", temp, convertedTemp);
    }
    
    return 0;
}