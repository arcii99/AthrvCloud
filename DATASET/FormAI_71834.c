//FormAI DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include<stdio.h> //standard input-output library

int main(){
    float fahrenheit, celsius; //variables to store temperature values

    //Displaying welcome message
    printf("Welcome to the temperature converter program!\n");

    //Getting temperature in celsius from the user
    printf("Please enter temperature in Celsius: \n");
    scanf("%f",&celsius);

    //Conversion of Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.1f Degree Celsius is equivalent to %.1f Degree Fahrenheit.\n", celsius,fahrenheit);

    printf("Do you want to convert Fahrenheit to Celsius? Press Y for Yes, any other key to exit. \n");

    char userInput;
    scanf(" %c", &userInput);  // Reading user input

    if (userInput == 'Y') { // If user wants to convert Fahrenheit to Celsius
        printf("Please enter temperature in Fahrenheit: \n");
        scanf("%f",&fahrenheit);

        //Conversion of Fahrenheit to Celsius
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("%.1f Degree Fahrenheit is equivalent to %.1f Degree Celsius.\n", fahrenheit, celsius);
        printf("Thank you for using this program!\n");
    } else {
        printf("Thank you for using this program!\n");
    }

    return 0; // end of program
}