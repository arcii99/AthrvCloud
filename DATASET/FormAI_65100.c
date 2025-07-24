//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;
    float temp, output;
    printf("====== Temperature Converter ======\n");
    printf("[C] Celsius to Fahrenheit\n");
    printf("[F] Fahrenheit to Celsius\n");
    printf("Please enter your choice:");
    scanf(" %c", &choice);

    if(choice == 'C' || choice == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);
        output = (temp * 9/5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n", temp, output);
    } else if(choice == 'F' || choice == 'f') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temp);
        output = (temp - 32) * 5/9;
        printf("%.2f Fahrenheit = %.2f Celsius\n", temp, output);
    } else {
        printf("Invalid choice. Program terminated.\n");
        exit(0);
    }

    return 0;
}