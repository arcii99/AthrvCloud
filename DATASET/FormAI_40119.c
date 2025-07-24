//FormAI DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    int choice;
    float value;
    printf("Welcome to the post-apocalyptic Unit Converter!\n");
    printf("Please select an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Miles to Kilometers\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the Fahrenheit value to convert: ");
            scanf("%f", &value);
            float celsius = (value - 32) * 5 / 9;
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", value, celsius);
            break;
        case 2:
            printf("Enter the Miles value to convert: ");
            scanf("%f", &value);
            float km = value * 1.60934;
            printf("%.2f Miles is equal to %.2f Kilometers.\n", value, km);
            break;
        default:
            printf("Invalid choice. Please select either 1 or 2.\n");
            break;
    }

    return 0;
}