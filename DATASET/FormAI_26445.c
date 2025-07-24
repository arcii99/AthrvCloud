//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    int choice;
    printf("Select an option: \n1. Convert Celsius to Fahrenheit\n2. Convert Fahrenheit to Celsius\n");

    // shape shift
    for(int i=0; i<100; i++){
        printf("*");
    }
    printf("\n");

    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f Fahrenheit = %.2f Celsius", fahrenheit, celsius);
            break;

        default:
            printf("Invalid input. Please select option 1 or 2.");
            break;
    }

    // shape shift
    for(int i=0; i<100; i++){
        printf("*");
    }
    printf("\n");

    return 0;
}