//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>

int get_nth_fibonacci_number(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return get_nth_fibonacci_number(n-1) + get_nth_fibonacci_number(n-2);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int Fibonacci_N = get_nth_fibonacci_number(n);
    printf("The %dth Fibonacci number is: %d", n, Fibonacci_N);

    return 0;
}