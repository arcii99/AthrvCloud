//FormAI DATASET v1.0 Category: Random ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A unique program to generate a series of random numbers
// using the C language.

int main() {

    int i, n;
    time_t t;

    // Use the time function to get a seed value for srand()
    srand((unsigned) time(&t));

    printf("How many random numbers do you want to generate? ");
    scanf("%d", &n);

    printf("Here are %d random numbers:\n", n);

    // Loop n number of times and generate a random number each time
    for (i = 0; i < n; i++) {
        printf("%d\n", rand());
    }

    return 0;
}