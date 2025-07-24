//FormAI DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>

int main() {
    float temperature, convertedTemperature;
    char choice;

    printf("Enter temperature: ");
    scanf("%f", &temperature);

    printf("Convert to (F)ahrenheit or (K)elvin?: ");
    scanf(" %c", &choice);

    switch(choice){

        case 'F':
        case 'f':
            convertedTemperature = temperature * 1.8 + 32;
            printf("%.2f°C = %.2f°F", temperature, convertedTemperature);
            break;

        case 'K':
        case 'k':
            convertedTemperature = temperature + 273.15;
            printf("%.2f°C = %.2fK", temperature, convertedTemperature);
            break;

        default:
            printf("Invalid choice. Please enter 'F' or 'K'");
            break;
    }

    return 0;
}