//FormAI DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include<stdio.h>

/*
This program converts units from Celsius to Fahrenheit and vice versa.
User enters the temperature in Celsius or Fahrenheit 
and then selects the conversion option.
*/

int main() {

    float temp, convertedTemp;
    int option;

    printf("Enter temperature value: ");
    scanf("%f", &temp);
    //get temperature value from user

    printf("Enter conversion option (1- Celsius -> Fahrenheit, 2- Fahrenheit -> Celsius): ");
    scanf("%d", &option);
    //get conversion option from user

    if(option == 1){
        convertedTemp = (temp * 9 / 5) + 32; // Celsius to Fahrenheit conversion formula
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", temp, convertedTemp);
    } else if(option == 2) {
        convertedTemp = (temp - 32) * 5 / 9; // Fahrenheit to Celsius conversion formula
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", temp, convertedTemp);
    } else {
        printf("Invalid option, please enter 1 or 2\n");
    }

    return 0;
}