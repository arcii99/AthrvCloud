//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>

int is_prime(int n) {
    if (n < 2) return 0;
    if (n % 2 == 0 && n > 2) return 0;
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    int count = 0;
    int n = 2;
    while(count < 100) {
        if(is_prime(n)) {
            printf("%d ", n);
            count++;
        }
        n++;
    }
    return 0;
}