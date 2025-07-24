//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int n, i, j, flag;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    // 2 is the smallest prime number
    printf("2 ");

    // Loop for checking every odd integer starting from 3
    for(i=3; i<=n; i+=2) {
        flag = 1; // Assume the number is prime
        // Check the number with every integer starting from 3 till its half
        for(j=3; j<=i/2; j+=2) {
            if(i%j == 0) {
                flag = 0; // Number is not a prime
                break;
            }
        }
        if(flag == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}