//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>

int main()
{
    int number, i, flag;

    printf("Enter a number: ");
    scanf("%d", &number);

    // 0 and 1 are not prime numbers
    if (number == 0 || number == 1) {
        printf("%d is not a prime number", number);
        return 0;
    }

    printf("Prime numbers below %d are:\n", number);

    // loop through all numbers less than input
    for (i = 2; i < number; i++) {
        flag = 0;

        // check if i is prime or not
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}