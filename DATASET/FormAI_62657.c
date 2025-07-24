//FormAI DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>

int main() {
    printf("Welcome to the CyberPunk Unit Converter!\n");
    int option;
    float value;
    printf("Please select an option:\n");
    printf("1. Convert meters to feet\n");
    printf("2. Convert kilometers to miles\n");
    printf("3. Convert Celsius to Fahrenheit\n");
    scanf("%d", &option);
    printf("Enter the value to convert:\n");
    scanf("%f", &value);
    switch(option) {
        case 1:
            printf("%.2f meters is equal to %.2f feet.\n", value, (value * 3.28));
            break;
        case 2:
            printf("%.2f kilometers is equal to %.2f miles.\n", value, (value * 0.621));
            break;
        case 3:
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", value, ((value * 9/5) + 32));
            break;
        default:
            printf("Invalid option! Please select a valid option.\n");
            break;
    }
    printf("Thank you for using the CyberPunk Unit Converter!\n");
    return 0;
}