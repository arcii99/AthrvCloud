//FormAI DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include<stdio.h>

int main(){

    float temperature, converted_temp;
    char choice;

    printf("Welcome to the Temperature Converter!\n\n");

    printf("Enter the temperature: ");
    scanf("%f",&temperature);

    printf("Is the temperature in Celsius or Fahrenheit? (C/F): ");
    scanf(" %c",&choice);

    if(choice == 'C' || choice == 'c'){
        converted_temp = temperature * 9/5 + 32;
        printf("\nThe temperature %0.2f°C is equal to %0.2f°F\n\n", temperature, converted_temp);

    }else if(choice == 'F' || choice == 'f'){
        converted_temp = (temperature - 32) * 5/9;
        printf("\nThe temperature %0.2f°F is equal to %0.2f°C\n\n", temperature, converted_temp);

    }else{
        printf("Invalid input! Please enter either C or F.\n");
    }

    return 0;
}