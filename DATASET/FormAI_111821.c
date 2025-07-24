//FormAI DATASET v1.0 Category: Temperature Converter ; Style: accurate
#include<stdio.h>

void CtoF(float celsius){
    float fahrenheit;
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2fC converted to Fahrenheit is %.2fF\n", celsius, fahrenheit);
}

void CtoK(float celsius){
    float kelvin;
    kelvin = celsius + 273.15;
    printf("%.2fC converted to Kelvin is %.2fK\n", celsius, kelvin);
}

int main(){
    float temperature;
    char choice;

    printf("Welcome to C Temperature Converter!\n");
    printf("Please enter the temperature you want to convert: ");
    scanf("%f", &temperature);

    printf("Please select the unit you want to convert to:\n");
    printf("Press F for Fahrenheit.\n");
    printf("Press K for Kelvin.\n");
    scanf("%s", &choice);

    switch(choice){
        case 'F':
            CtoF(temperature);
            break;
        case 'K':
            CtoK(temperature);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}