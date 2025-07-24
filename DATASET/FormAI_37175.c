//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: active
#include <stdio.h>

int main() {
    int num, i, flag;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Prime numbers between 1 and %d are: ", num);

    // loop through all numbers from 2 to given num
    for (i = 2; i <= num; i++) {
        flag = 0; // reset flag for each number

        // check if number i is prime
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        // if i is prime, print it
        if (flag == 0 && i != 1) {
            printf("%d ", i);
        }
    }

    return 0;
}