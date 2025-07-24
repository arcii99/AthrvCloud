//FormAI DATASET v1.0 Category: Temperature Converter ; Style: romantic
#include<stdio.h>

int main(){
    float fahrenheit, celsius;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5/9;

    printf("%.2f Fahrenheit is equal to %.2f Celsius", fahrenheit, celsius);

    return 0;
}