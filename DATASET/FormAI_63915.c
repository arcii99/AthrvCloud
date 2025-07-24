//FormAI DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>

//function to convert fahrenheit to celsius
float toCelsius(float fahrenheit){
    return (fahrenheit - 32) * (5.0/9.0);
}

//function to convert celsius to fahrenheit
float toFahrenheit(float celsius){
    return (celsius * (9.0/5.0)) + 32;
}

int main(){
    float temp;
    char unit;

    printf("Welcome to the Temperature Converter!\n");

    while(1){
        printf("Please enter the temperature and the unit (C or F): ");
        scanf("%f %c", &temp, &unit);

        if(unit == 'F' || unit == 'f'){
            printf("%f Fahrenheit is %f Celsius\n", temp, toCelsius(temp));
        }
        else if(unit == 'C' || unit == 'c'){
            printf("%f Celsius is %f Fahrenheit\n", temp, toFahrenheit(temp));
        }
        else{
            printf("Invalid input. Please try again.\n");
        }

        char choice;
        printf("Do you want to convert another temperature? Y/N: ");
        scanf(" %c", &choice);

        if(choice == 'N' || choice == 'n'){
            break;
        }
    }

    printf("Thank you for using the Temperature Converter!\n");

    return 0;
}