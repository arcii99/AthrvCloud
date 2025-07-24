//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

bool checkPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("The prime numbers between 1 and %d are:\n", num);
    
    bool isConfigurable = true;
    int start = 2;
    int end = num;
    
    if (isConfigurable) {
        printf("Enter starting range: ");
        scanf("%d", &start);
        printf("Enter ending range: ");
        scanf("%d", &end);
    }
    
    for (int i = start; i <= end; i++) {
        if (checkPrime(i)) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    
    return 0;
}