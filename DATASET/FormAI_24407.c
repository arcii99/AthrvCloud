//FormAI DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int choice;
    float value;
    printf("Welcome to the post-apocalyptic unit converter.\n");
    printf("Please select an option: \n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Miles per Hour to Kilometers per Hour\n");
    printf("3. Gallons to Liters\n");
    printf("4. Pounds to Kilograms\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter a value in Fahrenheit: ");
            scanf("%f", &value);
            printf("The corresponding value in Celsius is: %.2f\n", (value-32)*5/9);
            break;
        case 2:
            printf("Enter a value in Miles per Hour: ");
            scanf("%f", &value);
            printf("The corresponding value in Kilometers per Hour is: %.2f\n", value*1.60934);
            break;
        case 3:
            printf("Enter a value in Gallons: ");
            scanf("%f", &value);
            printf("The corresponding value in Liters is: %.2f\n", value*3.78541);
            break;
        case 4:
            printf("Enter a value in Pounds: ");
            scanf("%f", &value);
            printf("The corresponding value in Kilograms is: %.2f\n", value*0.453592);
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }
    printf("Thank you for using the post-apocalyptic unit converter.\n");
    return 0;
}