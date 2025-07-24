//FormAI DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>

float toFahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

float toKelvin(float celsius){
    return celsius + 273.15;
}

int main(){
    float temperatureInCelsius;
    char choice, go_again;

    do{
        printf("Enter temperature in Celsius:");
        scanf("%f", &temperatureInCelsius);

        printf("\nConvert to (F)ahrenheit or (K)elvin?:");
        scanf("%s", &choice);

        switch(tolower(choice)){
            case 'f':
                printf("\n%.2f C = %.2f F\n", temperatureInCelsius, toFahrenheit(temperatureInCelsius));
                break;
            case 'k':
                printf("\n%.2f C = %.2f K\n", temperatureInCelsius, toKelvin(temperatureInCelsius));
                break;
            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }

        printf("\nDo you want to convert another temperature? (y/n):");
        scanf("%s", &go_again);

    }while (tolower(go_again) == 'y');

    printf("\nThank you for using this converter!");

    return 0;
}