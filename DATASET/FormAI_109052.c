//FormAI DATASET v1.0 Category: Unit converter ; Style: peaceful
#include<stdio.h>

int main(){

    float celcius,fahrenheit;
    int choice;

    printf("Welcome to the Peaceful Unit Converter!\n");
    printf("Please select an option:\n");
    printf("\t1. Convert Celcius to Fahrenheit\n");
    printf("\t2. Convert Fahrenheit to Celcius\n");
    scanf("%d",&choice);

    if(choice == 1){
        printf("Enter the temperature in Celcius: ");
        scanf("%f",&celcius);
        //formula to convert Celcius to Fahrenheit
        fahrenheit = (9*celcius/5) + 32;
        printf("%.2f degrees Celcius is equal to %.2f degrees Fahrenheit.\n",celcius,fahrenheit);
    }
    else if(choice == 2){
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f",&fahrenheit);
        //formula to convert Fahrenheit to Celcius
        celcius = (fahrenheit - 32) * 5/9;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celcius.\n",fahrenheit,celcius);
    }
    else{
        printf("Invalid option selected. Please try again.\n");
    }

    printf("Thank you for using the Peaceful Unit Converter.\n");

    return 0;
}