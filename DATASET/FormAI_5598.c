//FormAI DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include<stdio.h>

int main(){

    printf("Welcome to the Temperature Converter!\n\n");
      
    float temperature;
    char unit;
  
    printf("Please enter the temperature: ");
    scanf("%f", &temperature);
  
    printf("Is it in Celsius or Fahrenheit? (C/F): ");
    scanf(" %c", &unit);
  
    if(unit == 'C' || unit == 'c'){
        temperature = temperature * 1.8 + 32;
        printf("\nTemperature in Fahrenheit: %.2f\n", temperature);
    }
    else if(unit == 'F' || unit == 'f'){
        temperature = (temperature - 32) / 1.8;
        printf("\nTemperature in Celsius: %.2f\n", temperature);
    }
    else{
        printf("\nInvalid input. Please enter either 'C' or 'F'.\n");
    }

    return 0;
}