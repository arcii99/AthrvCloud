//FormAI DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>

/**
 * This program calculates the sum of all odd numbers
 * between two inputted integers using a for loop.
 * If the inputted integers are the same, the program
 * will print "Invalid input".
 **/

int main() {
    int a, b, sum = 0;

    printf("Enter two integers: ");
    scanf("%d%d", &a, &b);

    if (a == b) {
        printf("Invalid input");
    } else {
        if (a < b) {
            for (int i = a + 1; i < b; i++) {
                if (i % 2 == 1) {
                    sum += i;
                }
            }
        } else {
            for (int i = b + 1; i < a; i++) {
                if (i % 2 == 1) {
                    sum += i;
                }
            }
        }

        printf("The sum of odd numbers between %d and %d is %d", a, b, sum);
    }

    return 0;
}