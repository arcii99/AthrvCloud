//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
#include<stdio.h>

int main(){
    int choice, temperature;
    float result;
    do{
        printf("Hello there! I am your friendly Celsius Temperature Converter. \n");
        printf("Please choose from the following options: \n");
        printf("1. Convert Celsius to Fahrenheit \n");
        printf("2. Convert Celsius to Kelvin \n");
        printf("3. Quit program \n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Please enter the temperature in Celsius: ");
                scanf("%d", &temperature);
                result = (temperature * 9/5) + 32;
                printf("%d degrees Celsius is %.2f degrees Fahrenheit.\n", temperature, result);
                break;
            case 2:
                printf("Please enter the temperature in Celsius: ");
                scanf("%d", &temperature);
                result = temperature + 273.15;
                printf("%d degrees Celsius is %.2f degrees Kelvin.\n", temperature, result);
                break;
            case 3:
                printf("Okay bye! Come back soon.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

    }while(choice != 3);

    return 0;
}