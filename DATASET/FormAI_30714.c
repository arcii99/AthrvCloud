//FormAI DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, reverse = 0, original;
    printf("Enter an integer: ");
    scanf("%d", &num);

    original = num;

    while (num != 0) {
        reverse = reverse * 10 + num % 10;
        num = num / 10;
    }

    printf("The reverse of %d is %d\n", original, reverse);

    if (original == reverse) {
        printf("%d is a palindrome number\n", original);
    } else {
        printf("%d is not a palindrome number\n", original);
    }

    // Find the sum of all even numbers between 1 and user input
    int sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 2; i <= num; i += 2) {
        sum += i;
    }

    printf("The sum of all even numbers between 1 and %d is %d\n", num, sum);

    return 0;
}