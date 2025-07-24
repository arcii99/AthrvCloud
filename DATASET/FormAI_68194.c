//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int count, num = 2;
    printf("Enter number of prime numbers required: ");
    scanf("%d", &count);
    printf("The first %d prime numbers are:\n", count);
    while (count > 0) {
        if (is_prime(num)) {
            printf("%d ", num);
            count--;
        }
        num++;
    }
    printf("\n");
    return 0;
}