//FormAI DATASET v1.0 Category: Recursive ; Style: excited
#include <stdio.h>

// Woohoo! This is going to be some crazy recursive example!
// Get ready for some intense coding!

int calculateFactorial(int num) {
    // Hold on tight, we're diving into the deep end of recursion!
    if (num == 0 || num == 1) {
        // Alright, we've hit the base case. Time to start climbing back up!
        return 1;
    } else {
        // Uh oh, looks like we're still going down...
        // But don't worry, we'll eventually hit the base case!
        return num * calculateFactorial(num - 1);
    }
}

int main() {
    // Let's test out our recursive function!
    printf("Welcome to the factorial calculator! Enter a non-negative integer: ");
    int input;
    scanf("%d", &input);
    if (input < 0) {
        // Oops, we can't calculate the factorial of a negative number!
        printf("Error: Factorial of negative number does not exist.");
    } else {
        // Looks like we've got a valid input, time to calculate the factorial!
        int result = calculateFactorial(input);
        printf("The factorial of %d is: %d", input, result);
    }
    return 0;
}