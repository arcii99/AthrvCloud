//FormAI DATASET v1.0 Category: Random ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n;
    srand(time(0));

    printf("Enter the number of random numbers you want to generate: ");
    scanf("%d", &n);

    printf("Your random numbers are:\n");

    for (i = 0; i < n; i++) {
        printf("%d\n", rand());
    }

    return 0;
}