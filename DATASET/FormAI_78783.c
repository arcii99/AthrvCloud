//FormAI DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>

int main() {
    float temp;
    char unit;
    
    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter the temperature you want to convert: ");
    scanf("%f", &temp);
    
    printf("Is that temperature in Celsius or Fahrenheit? (C/F): ");
    scanf(" %c", &unit);
    
    if (unit == 'C') {
        float converted_temp = (temp * 9/5) + 32;
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp, converted_temp);
    } else if (unit == 'F') {
        float converted_temp = (temp - 32) * 5/9;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temp, converted_temp);
    } else {
        printf("Sorry, I did not understand your input.\n");
    }
    
    printf("Thank you for using the Temperature Converter!\n");
    
    return 0;
}