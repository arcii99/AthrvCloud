//FormAI DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>

int main() {
    char choice;
    float temp, convertedTemp;
    printf("Welcome to Temperature Converter!\n");
    printf("Enter C to convert °C to °F\n");
    printf("Enter F to convert °F to °C\n");
    printf("Enter your choice: ");
    scanf("%c", &choice);
    
    switch(choice) {
        case 'C':
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            convertedTemp = (temp * 9/5) + 32;
            printf("%.2f°C is equal to %.2f°F", temp, convertedTemp);
            break;
        case 'F':
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            convertedTemp = (temp - 32) * 5/9;
            printf("%.2f°F is equal to %.2f°C", temp, convertedTemp);
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}