//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: random
#include <stdio.h>

int isPrime(int num) {
    int flag = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main() {
    int n, i;
    printf("Enter the number of prime numbers to be generated: ");
    scanf("%d",&n);

    if(n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Generating the first %d prime numbers:\n", n);
    printf("2\n");

    for (i = 3; n > 1; i += 2) {
        if (isPrime(i)) {
            printf("%d\n", i);
            n--;
        }
    }

    return 0;
}