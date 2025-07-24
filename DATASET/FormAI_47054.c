//FormAI DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>

int main() {
    char choice;
    float distance;
    const float KM_TO_MILE = 0.6213712;
    
    printf("Welcome to the unit converter!\n");
    printf("What would you like to convert? Enter K for kilometers to miles or M for miles to kilometers: ");
    scanf("%c", &choice);
    
    if (choice == 'K' || choice == 'k') {
        printf("Enter a distance in kilometers: ");
        scanf("%f", &distance);
        float miles = distance * KM_TO_MILE;
        printf("%.2f kilometers is equal to %.2f miles.\n", distance, miles);
    } else if (choice == 'M' || choice == 'm') {
        printf("Enter a distance in miles: ");
        scanf("%f", &distance);
        float kilometers = distance / KM_TO_MILE;
        printf("%.2f miles is equal to %.2f kilometers.\n", distance, kilometers);
    } else {
        printf("Invalid selection. Please enter either K or M.\n");
    }
    
    return 0;
}