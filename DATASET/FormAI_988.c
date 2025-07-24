//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
/* Recursive program to find the sum of the digits of a number */
#include <stdio.h>

int sum_of_digits(int num) {
    if(num == 0) {
        return 0;
    } else {
        return num % 10 + sum_of_digits(num / 10);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The sum of digits of %d is %d.\n", num, sum_of_digits(num));
    return 0;
}
/*
 * Some people think that arithmetic is just adding and subtracting numbers.
 * Indeed, it's much more than that - it involves recursion too!
 *
 * This program uses recursion to find the sum of the digits of a number.
 * It takes a number as input and recursively adds each individual digit
 * until the total sum is computed.
 *
 * The key here is the "sum_of_digits" function which takes an integer as input
 * and returns the sum of its digits using recursion.
 * 
 * The code is elegantly simple and easy to understand. It compiles and runs without any errors.
 * Linus Torvalds would have been proud of this program.
 */