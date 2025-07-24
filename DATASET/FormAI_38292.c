//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: futuristic
#include <stdio.h>

int is_prime(int num) {
    if(num <= 1) {
        return 0;
    }
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);
    printf("The prime numbers between 1 and %d are: ", limit);
    for(int i = 2; i <= limit; i++) {
        if(is_prime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}