//FormAI DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    float input, output;
    int choice;

    while(1) {
        printf("\nEnter 1 for converting Celsius to Fahrenheit\n");
        printf("Enter 2 for converting Fahrenheit to Celsius\n");
        printf("Enter 3 for converting Feet to Meters\n");
        printf("Enter 4 for converting Meters to Feet\n");
        printf("Enter 5 to quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &input);
                output = (input * 9 / 5) + 32;
                printf("%.2fC = %.2fF\n", input, output);
                break;
            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &input);
                output = (input - 32) * 5 / 9;
                printf("%.2fF = %.2fC\n", input, output);
                break;
            case 3:
                printf("\nEnter length in Feet: ");
                scanf("%f", &input);
                output = input * 0.3048;
                printf("%.2fft = %.2fm\n", input, output);
                break;
            case 4:
                printf("\nEnter length in Meters: ");
                scanf("%f", &input);
                output = input / 0.3048;
                printf("%.2fm = %.2fft\n", input, output);
                break;
            case 5:
                printf("\nQuitting program...\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    }
}