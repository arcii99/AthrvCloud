//FormAI DATASET v1.0 Category: Arithmetic ; Style: cheerful
#include <stdio.h> 

int main() 
{ 
    int x, y;

    printf("Hello there, let's do some arithmetic!\n"); 
    printf("Enter the first number: "); 
    scanf("%d", &x); 
    printf("Enter the second number: "); 
    scanf("%d", &y); 

    printf("\nGreat! Here are some calculations based on those two numbers:\n"); 

    // Addition
    printf("\n%d + %d = %d\n", x, y, x+y); 

    // Subtraction
    printf("%d - %d = %d\n", x, y, x-y); 

    // Multiplication
    printf("%d * %d = %d\n", x, y, x*y);

    // Division
    if (y != 0) {
        printf("%d / %d = %.2f\n", x, y, (float)x/y); 
    } else {
        printf("Oops! The second number can't be 0. Try again!\n");
    }

    // Modulus
    printf("%d %% %d = %d\n", x, y, x%y); 

    // Increment
    printf("Incrementing %d by 1: %d\n", x, ++x); 

    // Decrement
    printf("Decrementing %d by 1: %d\n", y, --y); 

    printf("\nThat was fun! Let's do it again sometime!\n");

    return 0; 
}