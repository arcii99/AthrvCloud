//FormAI DATASET v1.0 Category: Unit converter ; Style: puzzling
#include<stdio.h>

int main() {
    int menu_choice;
    float quantity, result;
    
    printf("Welcome to the Unit Converter!\n\n");
    
    do {
        printf("Please select an option:\n");
        printf("1. Inches to Centimeters\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &menu_choice);
        
        switch(menu_choice) {
            case 1:
                printf("Enter the quantity in inches: ");
                scanf("%f", &quantity);
                result = quantity * 2.54;
                printf("%.2f inches is equal to %.2f centimeters.\n\n", quantity, result);
                break;
            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &quantity);
                result = (quantity - 32) * 5 / 9;
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n\n", quantity, result);
                break;
            case 3:
                printf("Enter the distance in miles: ");
                scanf("%f", &quantity);
                result = quantity * 1.60934;
                printf("%.2f miles is equal to %.2f kilometers.\n\n", quantity, result);
                break;
            case 4:
                printf("Thank you for using the Unit Converter!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n\n");
                break;
        }
    } while(menu_choice != 4);

    return 0;
}