//FormAI DATASET v1.0 Category: Temperature Converter ; Style: careful
#include<stdio.h>

void printMenu();
float convertToFahrenheit(float);
float convertToKelvin(float);

int main(){
    float temp, tempInFah, tempInKel;
    int choice;
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temp);
    do{
        printMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                tempInFah = convertToFahrenheit(temp);
                printf("%.2fC is equal to %.2fF\n", temp, tempInFah);
                break;
            case 2:
                tempInKel = convertToKelvin(temp);
                printf("%.2fC is equal to %.2fK\n", temp, tempInKel);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input. Please enter a valid choice.\n");
                break;
        }
    }while(choice != 3);
    return 0;
}

void printMenu(){
    printf("Choose an option:\n");
    printf("1. Convert to Fahrenheit\n");
    printf("2. Convert to Kelvin\n");
    printf("3. Exit\n");
    printf("Enter a choice: ");
}

float convertToFahrenheit(float temp){
    return (temp * 9/5) + 32;
}

float convertToKelvin(float temp){
    return temp + 273.15;
}