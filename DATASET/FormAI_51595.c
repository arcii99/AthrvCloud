//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: scalable
#include <stdio.h>

int is_prime(int num) {
    if(num < 2) return 0; // not prime
    if(num == 2 || num == 3) return 1; // prime
    if(num % 2 == 0 || num % 3 == 0) return 0; // not prime
    int i = 5;
    int w = 2;
    while(i * i <= num) {
        if(num % i == 0) return 0; // not prime
        i += w;
        w = 6 - w; // toggle between 2 and 4 to skip multiples of 3 faster
    }
    return 1; // prime
}

int main() {
    int num, i;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Prime numbers between 1 and %d are:\n", num);
    for(i = 2; i <= num; i++) {
        if(is_prime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}