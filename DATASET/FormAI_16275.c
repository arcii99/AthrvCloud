//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

const int N = 1000;
volatile sig_atomic_t sig_flag = false;

void sig_handler(int sig) {
    sig_flag = true;
}

int compute_fibonacci_number(int n) {
    if (n <= 1) {
        return n;
    }
    return compute_fibonacci_number(n - 1) + compute_fibonacci_number(n - 2);
}

void recursive_fibonacci(int n, bool *is_needed) {
    if (*is_needed == false || sig_flag) return;
    if (n == 0 || n == 1) {
        printf("%d ", n);
    } else {
        recursive_fibonacci(n - 1, is_needed);
        recursive_fibonacci(n - 2, is_needed);
        int fib_number = compute_fibonacci_number(n - 1) + compute_fibonacci_number(n - 2);
        if (*is_needed == true && !sig_flag) {
            printf("%d ", fib_number);
        }
    }
}

int main(int argc, char *argv[]) {
    signal(SIGINT, sig_handler);
    bool is_needed = true;
    int n = 10;

    printf("Computing Fibonacci sequence of length %d\n", n);

    while (is_needed) {
        recursive_fibonacci(n, &is_needed);
        if (is_needed) {
            printf("\nDo you want to continue? (y/n) ");
            char answer;
            while (true) {
                answer = tolower(getchar());
                if (answer == 'y') {
                    break;
                } else if (answer == 'n') {
                    is_needed = false;
                    break;
                } else {
                    printf("Invalid option, please enter 'y' or 'n': ");
                }
            }
        }
    }

    printf("Done. Exiting.\n");
    return 0;
}