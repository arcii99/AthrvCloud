//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>

int main() {
    int num, i, flag;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The prime numbers from 2 to %d are: ", num);

    // loop through the numbers
    for (i = 2; i <= num; i++) {

        // Assume i is prime
        flag = 1;

        // Check if i is divisible by any number other than 1 and itself
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }

        // If i is prime, print it
        if (flag) {
            printf("%d ", i);
        }
    }
    return 0;
}