//FormAI DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>

int main(){
    float celsius, fahrenheit;
    int choice;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 1.8) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
    }
    else if(choice == 2){
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) / 1.8;
        printf("%.2f Fahrenheit = %.2f Celsius", fahrenheit, celsius);
    }
    else{
        printf("Invalid option selected!");
    }

    return 0;
}