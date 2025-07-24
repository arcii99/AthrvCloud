//FormAI DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>

//Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * (5.0/9.0);
}

int main() {
    float fTemp, cTemp;
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &fTemp);
    
    cTemp = fahrenheitToCelsius(fTemp);
    
    printf("The temperature in Celsius is: %.2f\n", cTemp);
    
    if(cTemp < 0) {
        printf("It's freezing outside! Stay warm\n");
    } else if(cTemp > 30) {
        printf("It's hot outside! Stay cool\n");
    }
    
    return 0;
}