//FormAI DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>

// Define an array of integers
int nums[] = {2, 4, 6, 8, 10};

// Define a recursive function to compute the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    // Print out the array of integers using a for loop
    printf("The array of integers is: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Compute the factorial of 5 using the recursive function
    int fact = factorial(5);
    printf("The factorial of 5 is: %d\n", fact);

    // Define a variable to hold the sum of the integers in the array
    int sum = 0;

    // Use a while loop to iterate over the array and compute the sum
    int i = 0;
    while (i < 5) {
        sum += nums[i];
        i++;
    }

    // Print out the sum of the integers in the array
    printf("The sum of the integers in the array is: %d\n", sum);

    // Use a do-while loop to print out the first 10 even numbers
    printf("The first 10 even numbers are: ");
    int j = 0;
    do {
        printf("%d ", j * 2);
        j++;
    } while (j < 10);
    printf("\n");

    return 0;
}