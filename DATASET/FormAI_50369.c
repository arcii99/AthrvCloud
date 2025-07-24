//FormAI DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include<stdio.h>

int main(){
    float farenheit, celsius;
    
    printf("Enter temperature in Farenheit: ");
    scanf("%f", &farenheit);
    
    celsius = (farenheit - 32) * 5/9;
    
    printf("%.2f Farenheit = %.2f Celsius", farenheit, celsius);
    
    return 0;
}