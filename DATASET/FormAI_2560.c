//FormAI DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>

int sum(int n) {
    if (n == 0) { // base case
        return 0;
    } else { // recursive case
        return n + sum(n-1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    while (num < 0) { // check if num is negative
        printf("Please enter a positive integer: ");
        scanf("%d", &num);
    }

    int ans = sum(num);
    printf("The sum of the numbers from 1 to %d is %d.\n", num, ans);
    return 0;
}