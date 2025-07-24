//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: intelligent
#include <stdio.h>

int main() {
    int n, i, flag;
    printf("Enter the value of n:");
    scanf("%d", &n);
    printf("Prime numbers between 1 and %d are: ", n);

    // loop through all numbers from 1 to n
    for (i = 2; i <= n; i++) {
        flag = 0;
        
        // loop through all numbers from 2 to i-1 to check if i is divisible
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1; // if i is divisible, set flag to 1
                break;
            }
        }
        if (flag == 0 && i != 1) {
            printf("%d ", i); // if i is not divisible, print it
        }
    }

    return 0;
}