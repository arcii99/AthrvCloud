//FormAI DATASET v1.0 Category: Educational ; Style: peaceful
#include <stdio.h>

int main() {
    // Declare necessary variables
    int num1, num2, sum;
    
    // Ask for user input
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    // Perform addition operation and store result in sum variable
    sum = num1 + num2;
    
    // Output the result to the user
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    
    // Check if the sum is an even number
    if (sum % 2 == 0) {
        printf("The sum is an even number.\n");
    } else {
        printf("The sum is an odd number.\n");
    }
    
    // Check if the sum is divisible by 3
    if (sum % 3 == 0) {
        printf("The sum is divisible by 3.\n");
    } else {
        printf("The sum is not divisible by 3.\n");
    }
    
    // Check if the sum is greater than or equal to 10
    if (sum >= 10) {
        printf("The sum is greater than or equal to 10.\n");
    } else {
        printf("The sum is less than 10.\n");
    }
    
    // Check if the first number is greater than the second number
    if (num1 > num2) {
        printf("The first number is greater than the second number.\n");
    } else {
        printf("The second number is greater than or equal to the first number.\n");
    }
    
    return 0;
}