//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>

int countDown(int n) {
    // Base case: when n is 0, print a happy message and return 0
    if (n == 0) {
        printf("Woo hoo! We've reached 0! Congratulations!\n");
        return 0;
    }
    // Recursive case: print current number and call function with decremented n
    else {
        printf("%d, ", n);
        return countDown(n-1);
    }
}

int main() {
    printf("Let's count down to 0 together, shall we?\n");
    countDown(10);
    return 0;
}