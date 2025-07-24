//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>

int isPrime(int number) {
    if(number < 2) {
        return 0;
    }
    for(int i = 2; i < number; i++) {
        if(number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, count = 0;
    printf("Enter the number of prime numbers you want: ");
    scanf("%d", &num);
    printf("Prime numbers:");
    for(int i = 2;; i++) {
        if(isPrime(i)) {
            count++;
            printf(" %d", i);
            if(count == num) {
                break;
            }
        }
    }
    return 0;
}