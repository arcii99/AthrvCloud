//FormAI DATASET v1.0 Category: Unit converter ; Style: Romeo and Juliet
#include <stdio.h>

// Define the conversion functions
double fahrenheit_to_celsius(double fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

double celsius_to_fahrenheit(double celsius){
    return (celsius * 9/5) + 32;
}

// Define the main function
int main(){

    // Print a greeting message
    printf("Greetings and salutations dear friend! Welcome to the unit converter program. \n");

    // Declare variables
    double temperature;
    char choice;

    // Ask the user for input
    printf("What is the current temperature you wish to convert? \n");
    scanf("%lf", &temperature);
    printf("Is it in 'C'elsius or 'F'ahrenheit? \n");
    scanf(" %c", &choice);

    // Convert temperature based on user choice using conditional statement
    if (choice == 'C' || choice == 'c'){
        printf("Oh fair and gentle maiden, I shall now convert %f Celsius to Fahrenheit, for thee. \n", temperature);
        printf("%f Celsius is %f Fahrenheit. \n", temperature, celsius_to_fahrenheit(temperature));
    }
    else if (choice == 'F' || choice == 'f'){
        printf("Oh brave and noble sir, I shall now convert %f Fahrenheit to Celsius, for thee. \n", temperature);
        printf("%f Fahrenheit is %f Celsius. \n", temperature, fahrenheit_to_celsius(temperature));
    }
    else{
        printf("Alas, I knoweth not that unit of measurement. Please try again. \n");
    }

    // Bid farewell to the user
    printf("Farewell, dear friend. May thy temperature be ever pleasant. \n");

    // Return 0 to indicate successful program execution
    return 0;
}