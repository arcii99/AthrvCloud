//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>

int main() {
    int choice;
    float value, result;
    
    printf("Welcome to the Puzzling Unit Converter! Choose an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Hours to Minutes\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Miles to Kilometers\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the Fahrenheit value: ");
            scanf("%f", &value);
            result = (5 * (value - 32)) / 9;
            printf("%.2f Fahrenheit is equal to %.2f Celsius. Solve this puzzling conversion!\n", value, result);
            break;
        case 2:
            printf("Enter the Hours value: ");
            scanf("%f", &value);
            result = value * 60;
            printf("%.2f Hours is equal to %.2f Minutes. Can you figure out how many minutes are in an hour?\n", value, result);
            break;
        case 3:
            printf("Enter the Kilograms value: ");
            scanf("%f", &value);
            result = value * 2.20462;
            printf("%.2f Kilograms is equal to %.2f Pounds. Puzzle: If 1 kilogram equals 2.20462 pounds, then how many pounds are in 10 kilograms?\n", value, result);
            break;
        case 4:
            printf("Enter the Miles value: ");
            scanf("%f", &value);
            result = value * 1.60934;
            printf("%.2f Miles is equal to %.2f Kilometers. Solve this puzzle: If 1 mile equals 1.60934 kilometers, then what is the distance in kilometers between two cities 30 miles apart?\n", value, result);
            break;
        default:
            printf("Invalid choice! Try again.\n");
    }
    
    return 0;
}