//FormAI DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main(){
    float tempF = 0.0;
    float tempC = 0.0;
    int option = 0;
    printf("Welcome to the Temperature Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("Option: ");
    scanf("%d", &option);

    if(option == 1){
        printf("Enter a temperature in Fahrenheit: ");
        scanf("%f", &tempF);
        tempC = (tempF - 32) * 5/9;
        printf("%.1f degrees Fahrenheit is equal to %.1f degrees Celsius.\n", tempF, tempC);
    }
    else if (option == 2){
        printf("Enter a temperature in Celsius: ");
        scanf("%f", &tempC);
        tempF = (tempC * 9/5) + 32;
        printf("%.1f degrees Celsius is equal to %.1f degrees Fahrenheit.\n", tempC, tempF);
    }
    else{
        printf("Invalid option selected, please try again.\n");
    }

    printf("Thank you for using the Temperature Converter!\n");
    return 0;
}