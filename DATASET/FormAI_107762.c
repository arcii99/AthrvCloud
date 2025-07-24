//FormAI DATASET v1.0 Category: Recursive ; Style: interoperable
#include <stdio.h>

int recursiveFunction(int n) {
    if(n<=0) {
        return 0;
    } else {
        return n + recursiveFunction(n-1);
    }
}

int main() {
    int userInput, result;
    printf("Enter a positive integer: ");
    scanf("%d", &userInput);
    result = recursiveFunction(userInput);
    printf("The sum from 1 to %d is: %d", userInput, result);
    return 0;
}