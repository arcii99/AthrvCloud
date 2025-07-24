//FormAI DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>

int main() {
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if(num < 0) {
        printf("Negative number entered.\n");
    }
    else {
        printf("Positive number entered.\n");
    }
    
    int fact = 1;
    for(int i=1; i<=num; i++) {
        fact *= i;
    }
    
    printf("Factorial of %d is %d\n", num, fact);
    
    int sum = 0;
    for(int i=1; i<=num; i++) {
        sum += i;
    }
    
    printf("Sum of natural numbers up to %d is %d\n", num, sum);
    
    int is_prime = 1;
    for(int i=2; i<=num/2; i++) {
        if(num % i == 0) {
            is_prime = 0;
            break;
        }
    }
    
    if(is_prime) {
        printf("%d is a prime number\n", num);
    }
    else {
        printf("%d is not a prime number\n", num);
    }
    
    return 0;
}