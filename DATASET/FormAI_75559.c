//FormAI DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>

int main() { 
    float celsius, fahrenheit;
    
    printf("Let's convert Celsius to Fahrenheit!\n");
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 1.8) + 32; // conversion formula
    
    printf("%.2f Celsius is equal to %.2f Fahrenheit!\n", celsius, fahrenheit);
    printf("Amazing isn't it? Do you want to convert another temperature? (y/n)\n");
    
    char choice;
    scanf(" %c", &choice);
    
    while (choice == 'y') { // loop to convert more temperatures
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &celsius);
        
        fahrenheit = (celsius * 1.8) + 32;
        
        printf("%.2f Celsius is equal to %.2f Fahrenheit!\n", celsius, fahrenheit);
        printf("Do you want to convert another temperature? (y/n)\n");
        scanf(" %c", &choice);
    }
    
    printf("Alright then. Stay cool!"); // exit message
    
    return 0;
}