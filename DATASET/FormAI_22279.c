//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>

int is_prime(int n) {
    if(n <= 1) return 0;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

void prime_generator(int n) {
    int count = 0;
    int num = 2;
    while(count < n) {
        if(is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
}

int main() {
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    prime_generator(n);
    
    return 0;
}