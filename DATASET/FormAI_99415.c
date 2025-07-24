//FormAI DATASET v1.0 Category: Temperature Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;
    double temp, convertedTemp;
    printf("Welcome to the Brave Temperature Converter Program!\n");
    printf("Are you converting from Celsius or Fahrenheit? (Type 'C' or 'F'): ");
    scanf("%c", &choice);
    if (choice == 'C' || choice == 'c') {
        printf("Enter the temperature in Celsius: ");
        scanf("%lf", &temp);
        convertedTemp = (temp * 9/5) + 32;
        printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temp, convertedTemp);
    } else if (choice == 'F' || choice == 'f') {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%lf", &temp);
        convertedTemp = (temp - 32) * 5/9;
        printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temp, convertedTemp);
    } else {
        printf("Invalid choice. Please try again.\n");
    }
    printf("Thank you for using the Brave Temperature Converter Program!\n");
    return 0;
}