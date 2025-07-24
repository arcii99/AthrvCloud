//FormAI DATASET v1.0 Category: Unit converter ; Style: curious
#include<stdio.h>

//Function to convert Celsius to Fahrenheit
float celsToFahr(float celsius){
    return (celsius * 9/5) + 32;
}

//Function to convert Fahrenheit to Celsius
float fahrToCels(float fahrenheit){
    return (fahrenheit - 32) * 5/9;
}

int main(){
    int choice;
    float temp;
    printf("Welcome to the curious unit converter!\n");
    printf("Which temperature unit would you like to convert?\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f",&temp);
            printf("%f Celsius is equal to %f Fahrenheit",temp,celsToFahr(temp));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f",&temp);
            printf("%f Fahrenheit is equal to %f Celsius",temp,fahrToCels(temp));
            break;
        default:
            printf("Invalid choice, please try again");
    }
    return 0;
}