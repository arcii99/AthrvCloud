//FormAI DATASET v1.0 Category: Temperature Converter ; Style: artistic
#include<stdio.h>

int main(){
    float celsius, fahrenheit;
    int option;
    printf("Enter 1 to convert from Celsius to Fahrenheit or enter 2 to convert from Fahrenheit to Celsius: ");
    scanf("%d", &option); //to take user input for conversion selection
    if(option==1){
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius); //to take user input for Celsius temperature
        fahrenheit = (celsius * 9/5) + 32; //to convert Celsius to Fahrenheit
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit); //to display the converted temperature
    }
    else if(option==2){
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit); //to take user input for Fahrenheit temperature
        celsius = (fahrenheit - 32) * 5/9; //to convert Fahrenheit to Celsius
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", fahrenheit, celsius); //to display the converted temperature
    }
    else{
        printf("Invalid option selected"); //to handle invalid conversion option input
    }
    return 0;
}