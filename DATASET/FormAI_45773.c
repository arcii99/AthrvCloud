//FormAI DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int sig_num) {
    printf("Error: Caught exception signal %d\n", sig_num);
    exit(sig_num);
}

int divide(int a, int b) {
    if (b == 0) {
        raise(SIGFPE); // raise a floating point exception
    }
    return a/b;
}

int main() {
    signal(SIGFPE, sig_handler); // register the signal handler for a division by zero
    int num1, num2, result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    result = divide(num1, num2);

    printf("Result: %d\n", result);

    return 0;
}