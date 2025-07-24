//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ultraprecise
#include <stdio.h>

int is_prime(int num);

int main(void) {
    int count = 0;
    int num = 2;

    printf("Prime Numbers: ");

    while (count < 50) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }

    return 0;
}

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}