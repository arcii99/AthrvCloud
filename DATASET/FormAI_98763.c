//FormAI DATASET v1.0 Category: Temperature Converter ; Style: brave
#include<stdio.h>

int main() {
    float temperature;
    char option;
    
    printf("Welcome to the brave temperature converter tool!\n");
    printf("What would you like to convert? (Celsius/Fahrenheit): ");
    scanf("%c", &option);
    
    if(option == 'C' || option == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temperature);
        printf("%.2f Celsius is equivalent to %.2f Fahrenheit.", temperature, (temperature * 9/5) + 32);
    }
    else if(option == 'F' || option == 'f') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temperature);
        printf("%.2f Fahrenheit is equivalent to %.2f Celsius.", temperature, (temperature - 32) * 5/9);
    }
    else {
        printf("Invalid option selected, please try again.");
    }
    
    return 0;
}