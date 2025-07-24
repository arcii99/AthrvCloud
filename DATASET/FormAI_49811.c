//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>

int isPrime(int num) {
    int i;
    for (i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}