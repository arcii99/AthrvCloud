//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Alan Touring
#include <stdio.h>

int main() {
    int n, i, flag;
    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("Prime numbers between 2 and %d are: ", n);

    // loop through all numbers between 2 to n
    for(i = 2; i <= n; i++) {
        flag = 0;
        // loop through all numbers between 2 to i/2
        for(int j = 2; j <= i/2; j++) {
            // check if the number is divisible by j
            if(i % j == 0) {
                // if yes, mark the flag as 1 and break out of the loop
                flag = 1;
                break;
            }
        }
        // if the flag is not 1, i.e. the number is prime, print it
        if(flag == 0 && i!=1)
            printf("%d ", i);
    }
    return 0;
}