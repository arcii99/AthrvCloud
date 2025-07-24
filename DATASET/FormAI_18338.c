//FormAI DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>

int main() {
    float temperature;
    int choice;
    
    printf("Enter 1 to convert Celsius to Fahrenheit or 2 to convert Fahrenheit to Celsius: ");
    scanf("%d", &choice);
    
    // converting Celsius to Fahrenheit
    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        float fahrenheit = (temperature * 9/5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, fahrenheit);
    }
    
    // converting Fahrenheit to Celsius
    else if (choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        float celsius = (temperature - 32) * 5/9;
        printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, celsius);
    }
    
    // invalid choice
    else {
        printf("Invalid choice! Please enter either 1 or 2.\n");
    }
    
    return 0;
}