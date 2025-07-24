//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>

int main() {

    printf("Welcome to Artistic Unit Converter Program!\n");
    
    float distanceInches;
    printf("Enter the distance in inches: ");
    scanf("%f", &distanceInches);
    
    float distanceFeet = distanceInches / 12.0;
    printf("%.2f inches is equal to %.2f feet\n", distanceInches, distanceFeet);
    
    int totalSeconds;
    printf("\nEnter total seconds: ");
    scanf("%d", &totalSeconds);
    
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    printf("%d seconds is equal to %d minutes and %d seconds\n", totalSeconds, minutes, seconds);
    
    float weightOunces;
    printf("\nEnter the weight in ounces: ");
    scanf("%f", &weightOunces);
    
    float weightPounds = weightOunces / 16.0;
    printf("%.2f ounces is equal to %.2f pounds\n", weightOunces, weightPounds);
    
    printf("\nThank you for using Artistic Unit Converter Program!\n");

    return 0;
}