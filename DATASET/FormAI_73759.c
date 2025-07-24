//FormAI DATASET v1.0 Category: Temperature Converter ; Style: brave
#include<stdio.h>

int main() {
    float temp_f, temp_c;
    int choice;
    printf("Welcome to the Temperature Converter!\n\n");
    printf("Choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temp_c);
            temp_f = (temp_c * 9/5) + 32;
            printf("%.2f Celsius is equivalent to %.2f Fahrenheit\n", temp_c, temp_f);
            break;
        }
        case 2: {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temp_f);
            temp_c = (temp_f - 32) * 5/9;
            printf("%.2f Fahrenheit is equivalent to %.2f Celsius\n", temp_f, temp_c);
            break;
        }
        default: {
            printf("Invalid choice!\n");
        }
    }
    printf("\nThank you for using the Temperature Converter!\n");
    return 0;
}