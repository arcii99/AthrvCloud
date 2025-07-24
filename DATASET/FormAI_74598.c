//FormAI DATASET v1.0 Category: Math exercise ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dividend, divisor, quotient, remainder;

    // generate random numbers for dividend and divisor
    srand(time(0));
    dividend = rand() % 100 + 1;
    divisor = rand() % 10 + 1;

    // prompt user to find quotient and remainder
    printf("Find the quotient and remainder of %d divided by %d:\n", dividend, divisor);

    // get user input and calculate quotient and remainder
    scanf("%d %d", &quotient, &remainder);
    int user_quotient = dividend / divisor;
    int user_remainder = dividend % divisor;

    // check if user's answers are correct and print results
    if (quotient == user_quotient && remainder == user_remainder) {
        printf("Correct! %d / %d = %d R %d\n", dividend, divisor, quotient, remainder);
    } else {
        printf("Sorry, the correct answers are: %d / %d = %d R %d\n", dividend, divisor, user_quotient, user_remainder);
    }

    return 0;
}