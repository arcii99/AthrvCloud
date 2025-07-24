//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>

int main() {
    int n, i, flag;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are: ", n);

    // loop through all numbers between 1 and n
    for(i=2; i<=n; i++) {
        flag = 0;

        // check if number is prime
        for(int j=2; j<=i/2; j++) {
            if(i % j == 0) {
                flag = 1;
                break;
            }
        }

        // print if number is prime
        if(flag == 0) {
            printf("%d, ", i);
        }
    }

    return 0;
}