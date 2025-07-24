//FormAI DATASET v1.0 Category: Random ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n;
    double x;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &n);
    printf("\n");
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        x = (double) rand() / RAND_MAX;
        printf("%lf\n", x);
    }
    return 0;
}