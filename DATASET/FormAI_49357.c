//FormAI DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>

void menu(){
    printf("\n===== UNIT CONVERTER =====\n\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Meters to Feet\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Fahrenheit to Celsius\n");
    printf("5. Celsius to Fahrenheit\n");
    printf("6. Quit\n\n");
    printf("Enter your choice (1-6): ");
}

int main(){
    int choice;
    double inches, cm, meters, feet, km, miles, fahrenheit, celsius;
    
    do {
        menu();
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("\nEnter a value in inches: ");
                scanf("%lf", &inches);
                cm = inches * 2.54;
                printf("%.2lf inches = %.2lf centimeters\n", inches, cm);
                break;
            case 2:
                printf("\nEnter a value in meters: ");
                scanf("%lf", &meters);
                feet = meters * 3.281;
                printf("%.2lf meters = %.2lf feet\n", meters, feet);
                break;
            case 3:
                printf("\nEnter a value in kilometers: ");
                scanf("%lf", &km);
                miles = km * 0.6214;
                printf("%.2lf kilometers = %.2lf miles\n", km, miles);
                break;
            case 4:
                printf("\nEnter a temperature in Fahrenheit: ");
                scanf("%lf", &fahrenheit);
                celsius = (fahrenheit - 32) * 5 / 9;
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", fahrenheit, celsius);
                break;
            case 5:
                printf("\nEnter a temperature in Celsius: ");
                scanf("%lf", &celsius);
                fahrenheit = (celsius * 9 / 5) + 32;
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", celsius, fahrenheit);
                break;
            case 6:
                printf("\nGoodbye.\n");
                break;
            default:
                printf("\nInvalid input. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}