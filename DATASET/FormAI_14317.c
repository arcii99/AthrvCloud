//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Alan Touring
//*******************************************************
//************* C Temperature Converter ********************
//*******************************************************

#include<stdio.h>

int main()
{
    float Celsius, Fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f",&Celsius);

    //Formula to convert Celsius to Fahrenheit
    Fahrenheit = (Celsius * 9/5) + 32;

    printf("\nTemperature in Fahrenheit: %.2f", Fahrenheit);

    return 0;
}