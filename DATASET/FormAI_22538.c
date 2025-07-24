//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include <stdio.h>

int main() {
    int num, i, flag, count = 0;
    
    printf("Enter a positive integer to generate prime numbers upto: ");
    scanf("%d", &num);

    printf("Prime numbers between 2 and %d are: ", num);

    // loop through all numbers from 2 to num
    for(i=2; i<=num; i++) {
        flag = 0;

        // check if i is a prime number
        for(int j=2; j<=i/2; j++) {
            if(i % j == 0) {
                flag = 1;   // i is not a prime number
                break;
            }
        }

        // if i is a prime number, print it
        if(flag == 0) {
            printf("%d, ", i);
            count++;
        }
    }

    printf("\nTotal number of prime numbers generated: %d", count);

    return 0;
}