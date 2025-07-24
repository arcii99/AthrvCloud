//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: futuristic
#include <stdio.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);

    printf("Generating %d prime numbers:\n", n);

    int i = 2;
    int count = 0;
    
    while (count < n) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
        i++;
    }

    printf("\n");
    return 0;
}