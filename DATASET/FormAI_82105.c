//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include<stdio.h>

int main(){
    printf("\nHi there! I am your temperature converter chatbot!\n");
    printf("\nI can help you convert temperature between Celsius and Fahrenheit!\n");
    printf("\nWould you like to convert from Celsius to Fahrenheit or Fahrenheit to Celsius?\n");
    printf("\nType C for Celsius to Fahrenheit and F for Fahrenheit to Celsius.\n");

    char conversionType; //variable to store user input for conversion type
    float temperatureInput; //variable to store user input for temperature
    
    scanf("%c", &conversionType); //read user input for conversion type
    fflush(stdin); //flush previous inputs
    
    if(conversionType == 'C' || conversionType == 'c'){
        printf("\nGreat! You have chosen Celsius to Fahrenheit conversion!\n");
        printf("\nPlease enter the temperature in Celsius:\n");
        
        scanf("%f", &temperatureInput); //read user input for temperature
        fflush(stdin); //flush previous input
        
        float temperatureFahrenheit = (temperatureInput * 9/5) + 32; //formula to convert Celsius to Fahrenheit
        printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperatureInput, temperatureFahrenheit); //display converted value
    }
    else if(conversionType == 'F' || conversionType == 'f'){
        printf("\nGreat! You have chosen Fahrenheit to Celsius conversion!\n");
        printf("\nPlease enter the temperature in Fahrenheit:\n");
        
        scanf("%f", &temperatureInput); //read user input for temperature
        fflush(stdin); //flush previous input
        
        float temperatureCelsius = (temperatureInput - 32) * 5/9; //formula to convert Fahrenheit to Celsius
        printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperatureInput, temperatureCelsius); //display converted value
    }
    else{
        printf("\nOops! Looks like you have entered an invalid option.\n");
        printf("\nPlease make sure you type C for Celsius to Fahrenheit conversion and F for Fahrenheit to Celsius conversion.\n");
    }

    printf("\nThanks for using our temperature converter chatbot!\n");
    return 0;
}