//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>

// This is a happy recursive program!
// It will count down to 1 and print a cheerful message at each step.
// After reaching 1, it will count back up to the original number.

void countDown(int n, int originalNumber) {
    if (n == 1) { // base case
        printf("Yay! We reached 1!\n");
        countUp(2, originalNumber);
    } else { // recursive case
        printf("We are at %d!\n", n);
        countDown(n-1, originalNumber);
    }
}

void countUp(int n, int originalNumber) {
    if (n > originalNumber) { // base case
        printf("We made it back up to %d!\n", originalNumber);
    } else { // recursive case
        printf("Now we are at %d!\n", n);
        countUp(n+1, originalNumber);
    }
}

int main() {
    printf("Let's count down and back up!\n");
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    countDown(num, num);
    return 0;
}