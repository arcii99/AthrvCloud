//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: satisfied
#include <stdio.h>

int is_prime(int n) {
    if(n <= 1) return 0;
    if(n <= 3) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the maximum range: ");
    scanf("%d", &n);

    printf("Prime numbers in the range [1, %d]:\n", n);

    for(int i = 2; i <= n; i++) {
        if(is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}