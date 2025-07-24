//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

int main() {
    int choice;
    float temperature, result;
    
    printf("***********Temperature Converter***********\n");
    printf("Enter 1 to convert Celsius to Fahrenheit\n");
    printf("Enter 2 to convert Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        result = (temperature * 9/5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit", temperature, result);
    }
    else if(choice == 2) {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        result = (temperature - 32) * 5/9;
        printf("%.2f Fahrenheit = %.2f Celsius", temperature, result);
    }
    else {
        printf("Invalid choice");
    }
    
    return 0;
}