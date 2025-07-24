//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>

int main() {
    float tempC, tempF;
    
    printf("Welcome to the Temperature Converter!\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &tempC);
    
    tempF = (tempC * 9 / 5) + 32;
    printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit.\n", tempC, tempF);

    printf("Do you want to convert another temperature?\n");
    printf("Enter 1 for Yes and 0 for No: ");
    int choice;
    scanf("%d", &choice);

    while (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &tempC);

        tempF = (tempC * 9 / 5) + 32;
        printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit.\n", tempC, tempF);

        printf("Do you want to convert another temperature?\n");
        printf("Enter 1 for Yes and 0 for No: ");
        scanf("%d", &choice);
    }

    printf("Thank you for using the Temperature Converter!\n");

    return 0;
}