//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: realistic
#include <stdio.h>

int main() {
    int limit, i, j, flag;

    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);

    printf("Prime numbers between 1 and %d are: ", limit);

    //loop through all the numbers up to the limit
    for (i = 1; i <= limit; i++) {
        //assuming number is prime initially
        flag = 1;
        //loop from 2 to i-1 to check if number is divisible by any other number
        for (j = 2; j < i; j++){
            if (i % j == 0){
                //if divisible, number is not prime
                flag = 0;
                break;
            }
        }
        //print number if it is prime
        if (flag == 1)
            printf("%d ", i);
    }

    return 0;
}