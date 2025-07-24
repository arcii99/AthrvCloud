//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>

int main() {
    printf("Hello there! I am a prime number generator program! Let's get started!\n");
    
    int start, end, i, j, flag;
    printf("Please enter a starting number: ");
    scanf("%d", &start);
    printf("Please enter an ending number: ");
    scanf("%d", &end);
    
    printf("Calculating prime numbers...\n\n");
    
    for (i = start; i <= end; i++) {
        if (i == 1 || i == 0) continue;
        flag = 1;
        for (j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) printf("%d is a prime number!\n", i);
    }
    
    printf("\nPrime number generation complete! Thank you for using this program!\n");
    return 0;
}