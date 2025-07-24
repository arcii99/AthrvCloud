//FormAI DATASET v1.0 Category: Arithmetic ; Style: portable
#include <stdio.h>

// function to calculate factorial of a number
int factorial(int num) {
    int fact = 1;
    for (int i=1; i<=num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num, sum=0;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // calculate and print the sum of first 5 factorials
    for (int i=1; i<=5; i++) {
        int fact = factorial(i);
        printf("%d! = %d\n", i, fact);
        sum += fact;
    }
    printf("Sum of first 5 factorials = %d\n", sum);
    
    // calculate and print the product of first 'num' even numbers
    int even_num = 2, prod = 1;
    for (int i=1; i<=num; i++) {
        prod *= even_num;
        even_num += 2;
    }
    printf("Product of first %d even numbers = %d\n", num, prod);
    
    // divide 'num' by the sum of its digits
    int temp = num, digit_sum = 0;
    while (temp > 0) {
        digit_sum += temp % 10;
        temp /= 10;
    }
    printf("%d / Sum of digits of %d = %.2f\n", num, num, (float)num/digit_sum);
    
    return 0;
}