//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>

int main() {
    float inputVal, outputVal;

    int userInput;
    printf("Select which type of conversion you want to perform: \n");
    printf("1. Inches to Centimeters\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &userInput);

    switch (userInput) {
        case 1:
            printf("Enter value in inches: ");
            scanf("%f", &inputVal);
            outputVal = inputVal * 2.54;
            printf("%f inches is equal to %f centimeters.", inputVal, outputVal);
            break;
        case 2:
            printf("Enter value in kilograms: ");
            scanf("%f", &inputVal);
            outputVal = inputVal * 2.205;
            printf("%f kilograms is equal to %f pounds.", inputVal, outputVal);
            break;
        case 3:
            printf("Enter value in Fahrenheit: ");
            scanf("%f", &inputVal);
            outputVal = (inputVal - 32) * 5 / 9;
            printf("%f Fahrenheit is equal to %f Celsius.", inputVal, outputVal);
            break;
        default:
            printf("Invalid input.");
            break;
    }

    return 0;
}