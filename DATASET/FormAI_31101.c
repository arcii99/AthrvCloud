//FormAI DATASET v1.0 Category: Recursive ; Style: standalone
#include <stdio.h>

int calculateFactorial(int num) {
    if(num == 1) { // Base case of recursion
        return 1;
    }
    else {
        return num * calculateFactorial(num-1); // Recursive case
    }
}

int main() {
    int num, factorial;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if(num < 0) { // Input validation
        printf("Error: Negative integer entered.");
        return 1;
    }
    else {
        factorial = calculateFactorial(num); // Calling the recursive function
        printf("%d! = %d", num, factorial);
        return 0;
    }
}