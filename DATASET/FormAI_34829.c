//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool is_palindrome(int num);

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (is_palindrome(num)) {
        printf("%d is a palindrome number!\n", num);
    } else {
        printf("%d is not a palindrome number.\n", num);
    }

    return 0;
}

bool is_palindrome(int num) {
    int copy_num = num;
    int num_length = 0;
    int i;
    int reversed_num = 0;

    while (copy_num != 0) {
        num_length++;
        copy_num /= 10;
    }

    copy_num = num;

    for (i = 0; i < num_length; i++) {
        reversed_num += (copy_num % 10) * pow(10, num_length - i - 1);
        copy_num /= 10;
    }

    return num == reversed_num;
}