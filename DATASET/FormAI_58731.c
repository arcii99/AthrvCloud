//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {
    /* Let's find the sum of the first 10 odd numbers */
    int sum = 0;

    for(int i = 1; i <= 19; i += 2) {
        sum += i;
    }

    printf("The sum of the first 10 odd numbers is: %d\n", sum);

    /* Now let's generate the first 20 prime numbers */
    int count = 0;

    for(int num = 2; count < 20; num++) {
        int is_prime = 1;

        for(int i = 2; i <= num/2; i++) {
            if(num % i == 0) {
                is_prime = 0;
                break;
            }
        }

        if(is_prime) {
            printf("%d ", num);
            count++;
        }
    }

    printf("\n");

    /* Finally, let's calculate the factorial of 5 */
    int fact = 1;

    for(int i = 1; i <= 5; i++) {
        fact *= i;
    }

    printf("The factorial of 5 is: %d\n", fact);

    return 0;
}