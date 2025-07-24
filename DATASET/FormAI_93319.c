//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include <stdio.h>

int recursiveFunction(int n) {
    if (n == 0) { // base case
        return 0;
    } else if (n == 1) { // base case
        return 1;
    } else { // recursive case
        int previous = recursiveFunction(n-1);
        int secondPrevious = recursiveFunction(n-2);
        return previous + secondPrevious;
    }
}

int main() {
    printf("Let's print the Fibonacci sequence using our recursive function!\n");
    int length;
    printf("Enter the length of the sequence: ");
    scanf("%d", &length);
    printf("Here is the sequence:\n");
    for (int i=0; i<length; i++) {
        printf("%d ", recursiveFunction(i));
    }
    printf("\n");
    return 0;
}