//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include<stdio.h>

int main(){
    float celsius, fahrenheit, kelvin;

    //reading input temperature in celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    //calculate temperature in fahrenheit
    fahrenheit = (celsius * 9/5) + 32;
    //calculate temperature in kelvin
    kelvin = celsius + 273.15;

    //display temperature in all three scales using printf
    printf("\nTemperature in Celsius: %.2f", celsius);
    printf("\nTemperature in Fahrenheit: %.2f", fahrenheit);
    printf("\nTemperature in Kelvin: %.2f", kelvin);

    return 0;
}