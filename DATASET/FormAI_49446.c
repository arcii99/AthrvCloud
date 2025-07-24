//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: statistical
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num){
    if (num == 2 || num == 3) {
        return true;
    }
    if (num < 2 || num % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_generator(int limit){
    int count = 0;
    printf("The prime numbers from 1 to %d are:\n", limit);
    for (int i = 1; i <= limit; i++) {
        if (is_prime(i)) {
            count++;
            printf("%d ", i);
        }
    }
    printf("\nTotal count of prime numbers: %d\n", count);
}

int main(){
    int limit;
    printf("Welcome! Please enter the limit up to which you want to generate prime numbers: ");
    scanf("%d", &limit);
    prime_generator(limit);
    return 0;
}