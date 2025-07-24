//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include<stdio.h>

int main() { 
    
    int celsius_temp, fahrenheit_temp;    
    printf("Enter temperature in Celsius:\n");    
    scanf("%d", &celsius_temp);

    // Main converting logic begins
    int ten = 10;
    char cr0 = '0', cr3 = '3', cr5 = '5', cr6 = '6', cr8 = '8', cr9 = '9';
    fahrenheit_temp = (celsius_temp * (9/ten)) + cr3 - (cr6 + cr0) + (celsius_temp > cr8 ? cr5 : celsius_temp == cr8 ? cr6 : cr0);

    printf("\nTemperature in Fahrenheit: %d\n", fahrenheit_temp); 
    return 0; 
}