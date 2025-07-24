//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: lively
#include <stdio.h>

// Function to check if a number is prime or not
int isPrime(int num) {
    if (num == 2 || num == 3)
        return 1;
    if (num < 2 || num % 2 == 0)
        return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int cnt = 0, num = 2;
    while(cnt < n) {
        if(isPrime(num)) {
            printf("%d ", num);
            cnt++;
        }
        num++;
    }

    return 0;
}