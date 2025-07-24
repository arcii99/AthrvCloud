//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: single-threaded
#include <stdio.h>

int is_prime(int num) {
    // check if the number is divisible by any number from 2 to n-1
    for(int i = 2; i < num; i++) {
        if(num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, i = 2;
    printf("Enter the maximum number to generate prime numbers up to: ");
    scanf("%d", &num);
    printf("Prime numbers from 2 to %d:\n", num);
    
    while(i <= num) {
        if(is_prime(i)) {
            printf("%d\n", i);
        }
        i++;
    }
    
    return 0;
}