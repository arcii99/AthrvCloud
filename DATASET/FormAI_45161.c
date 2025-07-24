//FormAI DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    int option;
    float value;
    printf("Welcome to the Surprise Unit Converter!\n");
    printf("Please choose an option:\n");
    printf("1. Feet to Meters \n"); 
    printf("2. Miles to Kilometers \n");
    printf("3. Fahrenheit to Celsius\n");
    scanf("%d", &option);

    switch(option) {
        case 1:
            printf("Enter the value in Feet: ");
            scanf("%f", &value);
            printf("The value in Meters is %.2f\n", value*0.3048);
            break;
        case 2:
            printf("Enter the value in Miles: ");
            scanf("%f", &value);
            printf("The value in Kilometers is %.2f\n", value*1.60934);
            break;
        case 3:
            printf("Enter the value in Fahrenheit: ");
            scanf("%f", &value);
            printf("The value in Celsius is %.2f\n", (value-32)*5/9);
            break;
        default:
            printf("Invalid option selected. Please try again.\n");
    }

    return 0;
}