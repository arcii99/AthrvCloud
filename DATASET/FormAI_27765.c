//FormAI DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>

int main() {

    char choice;
    float temp, convertedTemp;
    
    printf("Welcome to the Temperature Converter!\n\n");
    
    do {
        printf("Enter 'F' to convert Fahrenheit to Celsius.\n");
        printf("Enter 'C' to convert Celsius to Fahrenheit.\n");
        printf("Enter 'Q' to quit.\n");
        scanf(" %c", &choice);
    
        if(choice == 'F' || choice == 'f') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            convertedTemp = (temp - 32) / 1.8;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", temp, convertedTemp);
        }
        else if(choice == 'C' || choice == 'c') {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            convertedTemp = (temp * 9/5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n\n", temp, convertedTemp);
        }
        else if(choice == 'Q' || choice == 'q') {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid choice. Please enter 'F', 'C', or 'Q'.\n\n");
        }
        
    } while(choice != 'Q' || choice != 'q');

    return 0;
}