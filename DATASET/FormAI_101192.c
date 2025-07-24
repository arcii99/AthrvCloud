//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {

    long long num;
    int digit;
    int sum_even = 0, sum_odd = 0;
    int i = 0;
    int checksum;

    printf("Enter an integer: ");
    scanf("%lld", &num);

    // get every other digit starting from the right
    while (num > 0) {
        digit = num % 10;

        if (i % 2 == 0) {
            sum_even += digit;
        } else {
            sum_odd += digit;
        }

        num /= 10;
        i++;
    }

    // perform the checksum calculation
    checksum = (sum_even * 3 + sum_odd) % 10;

    printf("Checksum: %d\n", checksum);

    return 0;
}