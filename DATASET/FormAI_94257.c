//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include<stdio.h>

int main(){

    float tempCelcius, tempFahrenheit;
    int option;

    printf("Welcome to the Temperature Converter\n");
    
    //Menu Display
    printf("\nPlease Choose Any of the Following Options:\n");
    printf("------------------------------------------\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("------------------------------------------\n");

    scanf("%d", &option);

    switch (option){

        case 1:
            printf("Enter Temperature in Celsius: ");
            scanf("%f", &tempCelcius);

            tempFahrenheit = (tempCelcius * 9/5) + 32;            

            printf("Temperature in Fahrenheit: %.2f F\n", tempFahrenheit);

            break;
        
        case 2:
            printf("Enter Temperature in Fahrenheit: ");
            scanf("%f", &tempFahrenheit);

            tempCelcius = (tempFahrenheit - 32) * 5/9;

            printf("Temperature in Celsius: %.2f C\n", tempCelcius);

            break;
        
        default:
            printf("Invalid Option Selected!\n");
            break;

    }

    return 0;

}