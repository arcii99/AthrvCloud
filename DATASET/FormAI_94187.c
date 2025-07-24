//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scientific
#include <stdio.h>

int main(void) {
    float C,F,K;
    int choice;
    printf("Select the conversion method:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Kelvin to Celsius\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius degree: ");
            scanf("%f", &C);
            F = (C * 9/5) + 32;
            printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit\n", C, F);
            break;
        case 2:
            printf("Enter temperature in Celsius degree: ");
            scanf("%f", &C);
            K = C + 273.15;
            printf("%.2f degree Celsius is equal to %.2f degree Kelvin\n", C, K);
            break;
        case 3:
            printf("Enter temperature in Fahrenheit degree: ");
            scanf("%f", &F);
            C = (F - 32) * 5/9;
            printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius\n", F, C);
            break;
        case 4:
            printf("Enter temperature in Kelvin degree: ");
            scanf("%f", &K);
            C = K - 273.15;
            printf("%.2f degree Kelvin is equal to %.2f degree Celsius\n", K, C);
            break;
        default:
            printf("Invalid choice. Please select a valid option.");
    }

    return 0;
}