//FormAI DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
/*
 * Simplistic program to calculate the sum of the first n natural numbers.
 * Written by <Your Name>
 * 2019-08-01
 */

#include <stdio.h>

int main(void)
{
    int n = 10;  // Calculate the sum of the first 10 natural numbers
    int sum = 0;  // Start with a sum of 0

    // Loop through all the natural numbers from 1 to n and add them to the sum
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("The sum of the first %d natural numbers is %d\n", n, sum);

    return 0;
}