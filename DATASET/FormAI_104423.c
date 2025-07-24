//FormAI DATASET v1.0 Category: Temperature Converter ; Style: artistic
#include<stdio.h>

int main(){
    float temp_celsius, temp_fahrenheit;
    int choice;

    printf("\n\tCelsius and Fahrenheit Temperature Converter\n");

    do{
        printf("\n1. Celsius to Fahrenheit Conversion\n2. Fahrenheit to Celsius Conversion\n3. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);   
        
        switch(choice){
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temp_celsius);
                temp_fahrenheit = (temp_celsius * 9 / 5) + 32;
                printf("\n%.2f degree Celsius is equal to %.2f degree Fahrenheit\n", temp_celsius, temp_fahrenheit);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temp_fahrenheit);
                temp_celsius = (temp_fahrenheit - 32) * 5 / 9;
                printf("\n%.2f degree Fahrenheit is equal to %.2f degree Celsius\n", temp_fahrenheit, temp_celsius);
                break;

            case 3:
                printf("\nExiting...\n");
                break;
            
            default:
                printf("\nInvalid Choice! Please try again.\n");
                break;
        }

    }while(choice != 3);

    printf("\nThanks for using Celsius and Fahrenheit Temperature Converter!\n");

    return 0;
}