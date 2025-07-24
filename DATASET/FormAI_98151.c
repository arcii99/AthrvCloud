//FormAI DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>

int main() {
    float temperature_c, temperature_f;
    int choice;
    printf("Welcome to Temperature Converter v2.0\n");
    
    do {
        printf("Please select the temperature unit you want to convert: \n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Celsius to Fahrenheit
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature_c);
                temperature_f = temperature_c * 1.8f + 32;
                printf("%.2fC is %.2fF\n", temperature_c, temperature_f);
                break;
                
            case 2:
                // Fahrenheit to Celsius
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature_f);
                temperature_c = (temperature_f - 32) / 1.8f;
                printf("%.2fF is %.2fC\n", temperature_f, temperature_c);
                break;
                
            case 3:
                printf("Thank you for using Temperature Converter v2.0");
                break;
                
            default:
                printf("Please choose a valid option.\n");
        }
        
    } while(choice != 3);
    
    return 0;
}