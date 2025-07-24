//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: thoughtful
#include <stdio.h>

int main() {

    int i, j, flag, n;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The first %d prime numbers are:\n", n);

    // loop through the first n numbers
    for (i = 2; i <= n; i++) {
        
        flag = 0; // reset flag for each number
        
        // check for factors up to i/2 since anything larger won't be a factor
        for (j = 2; j <= i/2; j++) {

            if (i % j == 0) {
                flag = 1; // prime number found
                break;
            }
        }

        if (flag == 0) {
            printf("%d ", i); // print the prime number
        }
    }

    return 0;
}