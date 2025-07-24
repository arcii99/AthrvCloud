//FormAI DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>

// function to convert Fahrenheit to Celsius
float convertFtoC(float temperature) {
    return (temperature - 32) * 5/9;
}

int main() {
    float fahrenheit, celsius;
    int choice;
    do {
        printf("\n\nTemperature Monitor\n");
        printf("=============================\n\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter temperature in Celsius:");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 9/5) + 32;
                printf("\nTemperature in Fahrenheit: %.2f", fahrenheit);
                break;
            case 2:
                printf("\nEnter temperature in Fahrenheit:");
                scanf("%f", &fahrenheit);
                celsius = convertFtoC(fahrenheit);
                printf("\nTemperature in Celsius: %.2f", celsius);
                break;
            case 3:
                printf("\nExiting the program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}