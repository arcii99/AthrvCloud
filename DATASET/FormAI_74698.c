//FormAI DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>

float convertCToF(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

float convertFToC(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main() {
    int choice;
    float temperature, result;
    printf("\tTemperature Converter\n\n");
    
    do {
        printf(" 1 - Celsius to Fahrenheit\n");
        printf(" 2 - Fahrenheit to Celsius\n");
        printf(" 0 - Exit\n\n");
        printf(" Enter an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter Celsius temperature: ");
                scanf("%f", &temperature);

                result = convertCToF(temperature);
                printf("%.2f C = %.2f F\n\n", temperature, result);
                break;

            case 2:
                printf("\nEnter Fahrenheit temperature: ");
                scanf("%f", &temperature);

                result = convertFToC(temperature);
                printf("%.2f F = %.2f C\n\n", temperature, result);
                break;

            case 0:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid option. Please choose again.\n\n");
                break;
        }

    } while(choice != 0);

    return 0;
}