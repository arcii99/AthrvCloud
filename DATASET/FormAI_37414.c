//FormAI DATASET v1.0 Category: Temperature Converter ; Style: brave
// Brave C Temperature Converter program
#include<stdio.h>

int main() {
    char choice;
    float temp, result;
    do {
        printf("\n\t\t===Temperature Converter===\n\n");
        printf("Choose an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("\nEnter your choice (1 / 2 / 3): ");

        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temp);
                result = ((temp *9) / 5) + 32; // Celsius to Fahrenheit conversion
                printf("%.2f Celsius = %.2f Fahrenheit\n", temp, result);
                break;
            case '2':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                result = (temp - 32) * 5 / 9; // Fahrenheit to Celsius conversion
                printf("%.2f Fahrenheit = %.2f Celsius\n", temp, result);
                break;
            case '3':
                printf("Thanks for using our program!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while(choice != '3');

    return 0;
}