//FormAI DATASET v1.0 Category: Error handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numerator, denominator, quotient;
    printf("Enter numerator: ");
    scanf("%d", &numerator);
    printf("Enter denominator: ");
    scanf("%d", &denominator);
    
    if(denominator == 0) {
        printf("Oh no! Division by zero! Quick, do the Heimlich maneuver on the computer!\n");
        exit(1);
    } 
    // Oh no! Division by zero! Quick, do the Heimlich maneuver on the computer!

    quotient = numerator / denominator;
    printf("Result of division: %d\n", quotient);

    return 0;
}