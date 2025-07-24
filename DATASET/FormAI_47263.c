//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: minimalist
#include <stdio.h>

int is_prime(int num) {
    int i;
    if (num == 1 || num == 0) return 0;
    for (i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, i, cnt = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Prime numbers up to %d are: ", num);
    for (i = 2; i <= num; ++i) {
        if (is_prime(i)) {
            printf("%d ", i);
            ++cnt;
        }
    }
    printf("\nTotal number of prime numbers found: %d\n", cnt);
    return 0;
}