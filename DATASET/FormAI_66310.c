//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int max_num, i, j;
    bool is_prime;

    printf("Enter the maximum number: ");
    scanf("%d", &max_num);
    printf("The following are the prime numbers between 2 and %d:\n", max_num);

    for (i = 2; i <= max_num; i++) {
        is_prime = true;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            printf("%d\n", i);
        }
    }

    return 0;
}