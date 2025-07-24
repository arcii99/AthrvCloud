//FormAI DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;
    float celsius, fahrenheit; 
    
    printf("Enter C to convert Celsius to Fahrenheit or enter F to convert Fahrenheit to Celsius: "); 
    scanf("%c", &choice);

    if(choice == 'C' || choice == 'c'){
        printf("\nEnter temperature in Celsius: ");
        scanf("%f", &celsius);
        
        fahrenheit = (celsius * 9/5) + 32;
        printf("\n%.2f degree Celsius is equal to %.2f degree Fahrenheit.", celsius, fahrenheit);
    }
    else if(choice == 'F' || choice == 'f'){
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        
        celsius = (fahrenheit - 32) * 5/9;
        printf("\n%.2f degree Fahrenheit is equal to %.2f degree Celsius.", fahrenheit, celsius);
    }
    else{
        printf("\nInvalid choice.");
        exit(0);
    }
    
    return 0;
}