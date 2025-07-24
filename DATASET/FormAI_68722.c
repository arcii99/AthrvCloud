//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: inquisitive
#include <stdio.h>

int main() {
    int prime[1000], flag, i, j, n = 1;
    prime[0] = 2;

    printf("How many prime numbers you want to generate: ");
    scanf("%d", &n);

    for(i = 3; n > 1; i++) {
        flag = 1;
        for(j = 2; j < i; j++) {
            if(i % j == 0) {
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            prime[n - 1] = i;
            n--;
        }
    }

    printf("Prime numbers generated are: ");
    for(i = 0; i < 1000; i++) {
        if(prime[i] != 0) {
            printf("%d ", prime[i]);
        }
    }

    return 0;
}