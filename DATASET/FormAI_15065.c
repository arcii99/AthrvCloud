//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>

int main() {
    int n, first = 0, second = 1, next, i;

    printf("Enter the number of terms you want to display: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; ++i) {
        printf("%d, ", first);
        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");

    printf("The %dth term of the Fibonacci sequence is %d.\n", n, first);

    printf("\nLet me check if the sequence has any spy numbers...\n");

    int is_spy = 0;
    for (i = 1; i < n; i++) {
        int num = 0, temp = first, count = 0;
        while (temp != 0) {
            num = num + temp % 10;
            temp /= 10;
            count++;
        }
        if (num == second && count == 2) {
            printf("%d is a Spy number! Alert the FBI!\n", second);
            is_spy = 1;
            break;
        }
        first = second;
        second = num;
    }

    if (!is_spy) {
        printf("The Fibonacci sequence is safe from spy numbers... Or is it?\n");
    }

    return 0;
}