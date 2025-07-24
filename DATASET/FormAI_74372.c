//FormAI DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>

int main() {
    int choice;
    double value;
    
    printf("Welcome to the Medieval Unit Converter!\n");
    printf("Please select the unit you would like to convert:\n");
    printf("1. Peasant Hands\n");
    printf("2. Noble Fingers\n");
    printf("3. Squire Feet\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter the value in peasant hands: ");
            scanf("%lf", &value);
            printf("%.2f peasant hands is equal to %.2f noble fingers and %.2f squire feet.\n", value, value * 0.8, value * 0.35);
            break;
        case 2:
            printf("Enter the value in noble fingers: ");
            scanf("%lf", &value);
            printf("%.2f noble fingers is equal to %.2f peasant hands and %.2f squire feet.\n", value, value * 1.25, value * 0.44);
            break;
        case 3:
            printf("Enter the value in squire feet: ");
            scanf("%lf", &value);
            printf("%.2f squire feet is equal to %.2f peasant hands and %.2f noble fingers.\n", value, value * 2.86, value * 2.27);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    printf("Thank you for using the Medieval Unit Converter!\n");
    
    return 0;
}