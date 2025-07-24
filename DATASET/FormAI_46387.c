//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the most exciting C error handling program you've ever seen!\n\n");
    
    int numerator, denominator, quotient;
    
    printf("Enter the numerator: ");
    scanf("%d", &numerator);
    
    printf("Enter the denominator: ");
    scanf("%d", &denominator);

    if (denominator == 0) {
        printf("Oh no! You can't divide by zero, that's a big no no!\n");
        printf("Going to have to exit the program now, sorry about that :(\n");
        exit(1);
    }
    
    quotient = numerator / denominator;
    
    printf("%d divided by %d is %d\n", numerator, denominator, quotient);
    
    printf("Wooooo! We did it! No errors! This is so exciting!\n");
    return 0;
}