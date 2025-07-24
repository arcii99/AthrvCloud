//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num);

int main() {
    int i, n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);
    printf("\n");

    int count = 0;
    i = 2;
    while (count < n) {
        bool prime = is_prime(i);
        if (prime) {
            printf("%d\n", i);
            count++;
        }
        i++;
    }
    return 0;
}

bool is_prime(int num) 
{
    if (num <= 1)
        return false;
    else if (num == 2)
        return true;
    else {
        int i;
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
}