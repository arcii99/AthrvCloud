//FormAI DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include<stdio.h>
 
int main(){
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9/5) + 32; // formula to convert Celsius to Fahrenheit

    printf("%.2f Celsius is %.2f Fahrenheit", celsius, fahrenheit);

    return 0;
}