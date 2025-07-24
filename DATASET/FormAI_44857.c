//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);

int main(){
    int choice;
    float temp;
    printf("Enter temperature value: ");
    scanf("%f", &temp);
    printf("\nEnter choice:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("\n%.2fC = %.2fF\n", temp, celsius_to_fahrenheit(temp));
            break;
        case 2:
            printf("\n%.2fF = %.2fC\n", temp, fahrenheit_to_celsius(temp));
            break;
        default:
            printf("\nInvalid Choice!!\n");
    }
    return 0;
}

float celsius_to_fahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

float fahrenheit_to_celsius(float fahrenheit){
    return (fahrenheit - 32) * 5/9;
}