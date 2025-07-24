//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>

int main() {
    int num, i, j;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    for (i = 2; i <= num; i++) {
        int is_prime = 1;

        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}