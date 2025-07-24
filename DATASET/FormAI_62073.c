//FormAI DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>

int main() {
    int option;
    float value;
    
    printf("Welcome to the unit converter!\n");
    printf("Please choose an option:\n");
    printf("1) Convert Celsius to Fahrenheit\n");
    printf("2) Convert Fahrenheit to Celsius\n");
    printf("3) Convert Miles to Kilometers\n");
    printf("4) Convert Kilometers to Miles\n");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("Enter a temperature in Celsius: ");
            scanf("%f", &value);
            printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", value, (value*1.8)+32);
            break;
        case 2:
            printf("Enter a temperature in Fahrenheit: ");
            scanf("%f", &value);
            printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", value, (value-32)*(0.5556));
            break;
        case 3:
            printf("Enter a distance in miles: ");
            scanf("%f", &value);
            printf("%.2f miles is %.2f kilometers.\n", value, value*1.609);
            break;
        case 4:
            printf("Enter a distance in kilometers: ");
            scanf("%f", &value);
            printf("%.2f kilometers is %.2f miles.\n", value, value*0.6214);
            break;
        default:
            printf("Invalid option. Please choose again.\n");
            break;
    }
    
    return 0;
}