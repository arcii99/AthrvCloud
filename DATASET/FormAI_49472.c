//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shocked
#include <stdio.h>

int main() {
    int choice;
    float temp;

    printf("Choose conversion type: \n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp);
            temp = (temp * 9/5) + 32;
            printf("Temperature in Fahrenheit: %.2f", temp);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp);
            temp = (temp - 32) * 5/9;
            printf("Temperature in Celsius: %.2f", temp);
            break;
        default:
            printf("Invalid choice.");
    }

    return 0;
}