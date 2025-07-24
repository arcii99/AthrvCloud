//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>

int main() {
    int n, i, flag;
    
    printf("******** PRIME NUMBER GENERATOR ********\n");
    printf("Enter the number up to which you want to generate prime numbers: ");
    scanf("%d", &n);

    printf("Prime numbers between 1 and %d are: ", n);

    // loop through each number up to n
    for(i=2; i<=n; i++) {
        flag = 0; // assume i is a prime number

        // loop through each number up to i-1
        for(int j=2; j<i; j++) {
            if(i%j == 0) { // if i is divisible by j, it's not a prime
                flag = 1;
                break;
            }
        }

        if(flag == 0) { // if we didn't find a divisor, it's a prime number
            printf("%d ", i);
        }
    }

    return 0;
}