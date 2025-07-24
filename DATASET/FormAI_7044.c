//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>

int main() {
    printf("Welcome to the Prime Number Generator! \n\n");
    
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1) {
        printf("Invalid input. Please enter a number greater than 1. \n");
    } else {
        printf("The prime numbers up to %d are: \n", num);
        
        // generate prime numbers
        for (int i = 2; i <= num; i++) {
            int is_prime = 1;

            // check for prime
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    is_prime = 0;
                    break;
                }
            }

            // print prime number
            if (is_prime) {
                printf("%d ", i);
            }
        }

        printf("\n");
    }

    return 0;
}