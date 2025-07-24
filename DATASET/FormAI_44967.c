//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>

#define MAX 1000

// Find the sum of all multiples of 3 and 5 up to a specified maximum limit.
int main() {
    int n = 1000;
    int sum = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    printf("The sum of all multiples of 3 and 5 below %d is: %d\n", n, sum);

    return 0;
}