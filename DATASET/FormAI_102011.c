//FormAI DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>

int main() {
    int num1 = 9;
    int num2 = 3;
    
    printf("Let's perform some arithmetic operations on %d and %d\n", num1, num2);
    
    int sum = num1 + num2;
    int diff = num1 - num2;
    int product = num1 * num2;
    int quotient = num1 / num2;
    int mod = num1 % num2;
    
    if (mod == 0) {
        printf("Woah! The modulus of %d and %d is equal to 0! That means they have a perfect compatibility!\n\n", num1, num2);
    } else {
        printf("What the actual hell! The modulus of %d and %d is NOT equal to 0! This is an outrageous union!\n\n", num1, num2);
    }
    
    printf("Now let's increment and decrement %d and %d, respectively\n", num1, num2);
    
    num1++;
    num2--;
    
    printf("After incrementing %d and decrementing %d, we get the values %d and %d, respectively\n\n", num1 - 1, num2 + 1, num1, num2);
    
    printf("Now let's elevate %d to the power of %d and see what we get\n", num1, num2);
    
    int result = num1;
    
    for (int i = 1; i < num2; i++) {
        result *= num1;
    }
    
    printf("Holy smokes! %d raised to the power of %d is equal to %d! This is an insanity!\n", num1, num2, result);
    
    return 0;
}