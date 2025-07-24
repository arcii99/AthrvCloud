//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>

int main() {
    int num, i, j, flag, count = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Edge cases for numbers less than 2
    if (num < 2) {
        printf("There are no prime numbers less than 2.");
        return 0;
    }
    
    printf("The prime numbers from 2 to %d are: \n", num);
    
    // Loop through each number from 2 to num
    for (i = 2; i <= num; i++) {
        flag = 0;
        
        // Check if the current number is prime
        for (j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        
        // If the current number is prime, print it
        if (flag == 0) {
            printf("%d ", i);
            count++;
        }
    }
    
    printf("\nThere are %d prime numbers from 2 to %d.", count, num);
    
    return 0;
}