//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include <stdio.h>

int recursiveFactorial(int num) {
    // Base case: Factorial of 0 is 1
    if (num == 0) {
        printf("Base Case Reached: factorial of 0 is 1\n");
        return 1;
    }

    // Recursive Case: Call the function with num-1 and multiply by current num
    printf("Calling recursive function with num=%d\n", num);
    int result = num * recursiveFactorial(num - 1);
    printf("Returning from recursive function with num=%d, result=%d\n", num, result);
    return result;
}

int main() {
    int num;
    printf("****** Recursive Factorial Calculator ******\n");
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Factorial of negative numbers is not defined.\n");
        return 1; // Error code
    }

    printf("Calculating factorial of %d\n", num);
    int result = recursiveFactorial(num);
    printf("Factorial of %d is %d\n", num, result);
    return 0; // Success code
}